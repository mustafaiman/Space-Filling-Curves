#include "curvewidget.h"
#include <QMouseEvent>
#include <sstream>
#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

CurveWidget::CurveWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    isSpaceFillingCurve = false;
    numVertices = 0;
    state = STILL;
    isFilled = false;
    polygonColor[0]=1.0;
    polygonColor[1]=1.0;
    polygonColor[2]=1.0;
    polygonColor[3]=1.0;
    totalIteration = 0;
    originalNumVertices = 0;

    lineColor[0]=0.0;
    lineColor[1]=0.0;
    lineColor[2]=1.0;
    lineColor[3]=1.0;

    bgColor[0]=1.0;
    bgColor[1]=1.0;
    bgColor[2]=1.0;
    bgColor[3]=1.0;

    thickness = 1.0;
    widgetWidth = width();
    widgetHeight = height();

    setMouseTracking(true);

}

void CurveWidget::initShaders() {
    // Init Qt resource file
    Q_INIT_RESOURCE(resources);

    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QGLShader::Vertex, ":/vshader.glsl"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QGLShader::Fragment, ":/fshader.glsl"))
        close();

    // Link shader pipeline
    if (!program.link())
        close();

    // Bind shader pipeline for use
    if (!program.bind())
        close();
}

void CurveWidget::initializeGL() {
    initializeGLFunctions();
    //glEnable(GL_MULTISAMPLE);
    initShaders();

    /////////////////

    //create buffer
    glGenBuffers(1, &bufferId);
    glBindBuffer(GL_ARRAY_BUFFER, bufferId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    int vPosition = program.attributeLocation("vPosition");
    program.enableAttributeArray(vPosition);
    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

    program.setUniformValue("vertexColor",QVector4D(lineColor[0],lineColor[1],lineColor[2],lineColor[3]));

}

void CurveWidget::paintGL() {
    glClearColor(bgColor[0],bgColor[1],bgColor[2],bgColor[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    if(state==DYNAMIC) {
        glDrawArrays(GL_LINE_STRIP, 0, numVertices+1);

    } else {
        if(isFilled && !isSpaceFillingCurve) {
            glDrawArrays(GL_TRIANGLE_FAN, 0, numVertices);
        } else {
            glDrawArrays(GL_LINE_LOOP, 0, numVertices);
        }
    }


}

void CurveWidget::resizeGL(int width, int height) {
    // Set OpenGL viewport to cover whole widget
    glViewport(0, 0, width, height);
    widgetWidth = width;
    widgetHeight = height;
}

float CurveWidget::getRelativeX(int x) {
    return (float)x / (widgetWidth / 2) - 1.0;
}

float CurveWidget::getRelativeY(int y) {
    return (float)(widgetHeight - y) / (widgetHeight / 2) - 1.0;
}

void CurveWidget::mouseReleaseEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        //set default cursor
        unsetCursor();
        if( getDistance(point2(getRelativeX(event->x()),getRelativeY(event->y())),vertices[0]) < proximityConst) {
            //if distance to the first vertex is close enough, then complete the polygon
            state = STILL;
            originalNumVertices = numVertices;
            for(int i=0;i<numVertices;i++)
                originalPolygon[i] = vertices[i];

        } else {
            state = DYNAMIC;
            //last added point
            vertices[numVertices++] = point2(getRelativeX(event->x()), getRelativeY(event->y()));

            //vertex for the point under mouse
            vertices[numVertices]=vertices[numVertices-1];

            //update buffer
            glBufferSubData(GL_ARRAY_BUFFER, 0, (numVertices+1)*sizeof(point2), vertices);
        }

    }
    update();
}

void CurveWidget::mouseMoveEvent(QMouseEvent *event) {

    //if distance to the first vertex is close enough, then change cursor
    if( state == DYNAMIC && getDistance(point2(getRelativeX(event->x()),getRelativeY(event->y())),vertices[0]) < proximityConst) {
        setCursor(Qt::CrossCursor);

    } else {
        unsetCursor();
    }
    if(state == DYNAMIC) {
        vertices[numVertices] = point2(getRelativeX(event->x()), getRelativeY(event->y()));
        glBufferSubData(GL_ARRAY_BUFFER, 0, (numVertices+1)*sizeof(point2), vertices);
    }
    update();
}

void CurveWidget::applySpaceFilling(int level) {
    if(level < 1)
        return;
    totalIteration += level;
    isSpaceFillingCurve = TRUE;
    point2 *temp = new point2[NUM_VERTICES];
    point2 *v = vertices;


    while(level-->0) {
        int index = 0;
        for (int i = 0; i < numVertices; i++) {
            point2 last;

            temp[index++] = v[i];
            point2 interpoint1 = temp[index++] = (v[(i + 1) % numVertices] - v[i]) / 4 + v[i];
            point2 interpoint4 = (v[(i + 1) % numVertices] - v[i]) / 2 + v[i];
            point2 interpoint7 = v[(i + 1) % numVertices] - (v[(i + 1) % numVertices] - v[i]) / 4;
            point2 interpoint2 = temp[index++] = rotate270*(v[i] - interpoint1) + interpoint1;
            point2 interpoint3 = temp[index++] = rotate90*(interpoint1 - interpoint2) + interpoint2;
            temp[index++] = interpoint4;
            point2 interpoint5 = temp[index++] = rotate270*(interpoint7 - interpoint4) + interpoint4;
            point2 interpoint6 = temp[index++] = rotate270*(interpoint4 - interpoint5) + interpoint5;
            temp[index++] = interpoint7;
        }
        numVertices = index;
        for (int i = 0; i < index; i++)
            v[i] = vertices[i] = temp[i];
    }


    glBufferSubData(GL_ARRAY_BUFFER, 0, numVertices*sizeof(point2), vertices);
    update();
}

void CurveWidget::setBackgroundColor(int index, float val) {
    //index= 0:r, 1:g, 2:b, 3:a
    bgColor[index] = val;
    update();
}

void CurveWidget::setLineColor(int index, float val) {
    //index= 0:r, 1:g, 2:b, 3:a
    lineColor[index] = val;
    program.setUniformValue("vertexColor",QVector4D(lineColor[0],lineColor[1],lineColor[2],lineColor[3]));
    update();
}

void CurveWidget::setPolygonColor(int index, float val) {
    //index= 0:r, 1:g, 2:b, 3:a
    polygonColor[index] = val;
    update();
}

void CurveWidget::setFill(int st) {
    if(st==0)
        isFilled=false;
    else
        isFilled=true;
    update();
}

float *CurveWidget::getBgColor() {
    return bgColor;
}

float *CurveWidget::getLineColor() {
    return lineColor;
}

float *CurveWidget::getPolygonColor() {
    return polygonColor;
}

float CurveWidget::getDistance(point2 a, point2 b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

void CurveWidget::setLineWidth(int w) {
    glLineWidth((float)w);
    update();
}

std::string CurveWidget::dumpCurve() {
    std::ostringstream str;
    str << bgColor[0] << " " << bgColor[1] << " " << bgColor[2] << " " << bgColor[3] << " "
        << lineColor[0] << " " << lineColor[1] << " " << lineColor[2] << " " << lineColor[3] << " ";
    str << totalIteration << " ";
    str <<  originalNumVertices << " ";
    for(int i = 0; i< originalNumVertices; i++) {
        str << (float)(originalPolygon[i].x) << " ";
        str << originalPolygon[i].y << " ";
    }
    str << "\n";
    return str.str();
}

void CurveWidget::loadCurve(float *bg, float *line,int it, int n, float *f1, float *f2) {
    isSpaceFillingCurve = false;
    numVertices = 0;
    totalIteration = 0;
    state = STILL;
    bgColor[0] = bg[0];bgColor[1] = bg[1];bgColor[2] = bg[2];bgColor[3] = bg[3];
    lineColor[0] = line[0];lineColor[1] = line[1];lineColor[2] = line[2];lineColor[3] = line[3];
    update();
    numVertices = originalNumVertices = n;
    for(int i=0;i<numVertices;i++)
        originalPolygon[i] = vertices[i] = point2(f1[i],f2[i]);
    applySpaceFilling(it);
    glBufferSubData(GL_ARRAY_BUFFER, 0, (numVertices+1)*sizeof(point2), vertices);
    update();

}

void CurveWidget::clearCurve() {
    isSpaceFillingCurve = false;
    numVertices = 0;
    totalIteration = 0;
    state = STILL;
    bgColor[0] = 1.0;bgColor[1] = 1.0;bgColor[2] = 1.0;bgColor[3] = 1.0;
    lineColor[0] = 0.0;lineColor[1] = 0.0;lineColor[2] = 1.0;lineColor[3] = 1.0;
    glBufferSubData(GL_ARRAY_BUFFER, 0, (numVertices+1)*sizeof(point2), vertices);
    update();

}
