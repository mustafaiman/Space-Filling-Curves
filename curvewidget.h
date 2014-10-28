#ifndef CURVEWIDGET_H
#define CURVEWIDGET_H
#include<gl/glew.h>
#include <QGLWidget>
#include <QGLFunctions>
#include <QGLShaderProgram>
#include <string>
#include "Angel.h"

#define NUM_VERTICES 10000000
#define WIN_W glutGet(GLUT_WINDOW_WIDTH)
#define WIN_H glutGet(GLUT_WINDOW_HEIGHT)

typedef Angel::vec4 color4;
typedef Angel::vec2 point2;

class CurveWidget : public QGLWidget, protected QGLFunctions
{
    Q_OBJECT
public:
    explicit CurveWidget(QWidget *parent = 0);
    enum PolygonStateEnum {
        STILL,
        DYNAMIC
    };
    float *getBgColor();
    float *getLineColor();
    float *getPolygonColor();
    void applySpaceFilling(int level);
    std::string dumpCurve();
    void loadCurve(float *bg, float *line, int it, int n, float *f1, float *f2);
    void clearCurve();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    //curve properties
    bool isSpaceFillingCurve;
    int numVertices;
    PolygonStateEnum state;
    bool isFilled;
    float polygonColor[4];
    float lineColor[4];
    float bgColor[4];
    float thickness;
    point2 vertices[NUM_VERTICES];
    point2 originalPolygon[NUM_VERTICES];
    int totalIteration;
    int originalNumVertices;

    const mat2 rotate270 = mat2(0.0, -1.0, 1.0, 0.0);
    const mat2 rotate90 = mat2(0.0, 1.0, -1.0, 0.0);
    const float proximityConst = 0.0003;

    //widget properties
    QGLShaderProgram program;
    GLuint bufferId;
    int widgetWidth;
    int widgetHeight;

    void initShaders();
    float getRelativeX(int x);
    float getRelativeY(int y);
    float getDistance(point2 a, point2 b);

signals:

public slots:
    void setBackgroundColor(int index, float val);
    void setLineColor(int index, float val);
    void setPolygonColor(int index, float val);
    void setFill(int st);
    void setLineWidth(int w);

};

#endif // CURVEWIDGET_H
