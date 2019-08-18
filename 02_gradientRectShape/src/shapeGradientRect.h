//
//  shapeGradientRect.h
//  02_gradientRectShape
//
//  Created by alp tugan on 18.08.2019.
//

#ifndef shapeGradientRect_h
#define shapeGradientRect_h

#include "ofMain.h"

// Todo
// - radial fill
// - gradient directions

typedef enum {LINEAR, RADIAL} shapeFillMode;
typedef enum {VERTICAL, HORIZONTAL, DIAGONAL, DIAGONAL_REV} shapeFillDirection;

class shapeGradientRect : public ofRectangle {
private:
    float * vtxArray;
    float * clrArray;
    shapeFillDirection dir;
    
public:
    shapeGradientRect() {
        
        vtxArray = new float[8];
        clrArray = new float[16];
        
    }
    
    ~shapeGradientRect() {
        delete vtxArray;
        delete clrArray;
    }
    
    void setColors(ofColor _beginCl, ofColor _endCl, shapeFillDirection _dir = HORIZONTAL) {
        
        ofColor bgClrTL; //rgba
        ofColor bgClrTR; //rgba
        ofColor bgClrBL; //rgba
        ofColor bgClrBR; //rgba
        
        dir = _dir;
        
        switch(_dir) {
            case HORIZONTAL:
                bgClrTL = _beginCl; //rgba
                bgClrTR = _endCl; //rgba
                bgClrBL = _beginCl; //rgba
                bgClrBR = _endCl; //rgba
            break;
                
            case VERTICAL:
                bgClrTL = _beginCl; //rgba
                bgClrTR = _beginCl; //rgba
                bgClrBL = _endCl; //rgba
                bgClrBR = _endCl; //rgba
            break;
                
            case DIAGONAL:
                bgClrTL = _beginCl; //rgba
                bgClrTR = _endCl; //rgba
                bgClrBL = _endCl; //rgba
                bgClrBR = _beginCl; //rgba
            break;
                
            case DIAGONAL_REV:
                bgClrTL = _endCl; //rgba
                bgClrTR = _beginCl; //rgba
                bgClrBL = _beginCl; //rgba
                bgClrBR = _endCl; //rgba
            break;
                
        }
        
        clrArray[0] = bgClrTL.r / 255.0f; // red
        clrArray[1] = bgClrTL.g / 255.0f; // green
        clrArray[2] = bgClrTL.b / 255.0f; // blue
        clrArray[3] = bgClrTL.a / 255.0f; // alpha
        
        // color 2: top right
        clrArray[4] = bgClrTR.r / 255.0f; // red
        clrArray[5] = bgClrTR.g / 255.0f; // green
        clrArray[6] = bgClrTR.b / 255.0f; // blue
        clrArray[7] = bgClrTR.a / 255.0f; // alpha
        
        // color 3: bottom left
        clrArray[8] = bgClrBL.r / 255.0f; // red
        clrArray[9] = bgClrBL.g / 255.0f; // green
        clrArray[10] = bgClrBL.b / 255.0f; // blue
        clrArray[11] = bgClrBL.a / 255.0f; // alpha
        
        // color 4: bottom right
        clrArray[12] = bgClrBR.r / 255.0f; // red
        clrArray[13] = bgClrBR.g / 255.0f; // green
        clrArray[14] = bgClrBR.b / 255.0f; // blue
        clrArray[15] = bgClrBR.a / 255.0f; // alpha
    }
    
    void draw(int _x, int _y, int _w, int _h) {
        
        
        ofPushMatrix();
        /*switch(dir) {
            case DIAGONAL_REV:
                ofTranslate(_x , 0);
                ofRotateDeg(10);
            break;
                
            default:
                
            break;
                
        }
        cout << "ofGetMouseX() , ofGetMouseY()  " << ofGetMouseX()  << " " << this->y +  this->height << endl;*/
        this->x = _x;
        this->y = _y;
        this->width = _w;
        this->height = _h;
        
        vtxArray[0] = this->x;                      // TL x
        vtxArray[1] = this->y;                      // TL y
        vtxArray[2] = this->x + this->getWidth();   // TR x
        vtxArray[3] = this->y;                      // TR y
        vtxArray[4] = this->x;                      // BL x
        vtxArray[5] = this->y + this->getHeight();  // BL y
        vtxArray[6] = this->x + this->getWidth();   // BR x
        vtxArray[7] = this->y + this->getHeight();  // BR y
        /*
         glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer)
         size: The number of vertex coordinates, 2 for 2D points, 3 for 3D points.
         type: GL_FLOAT, GL_SHORT, GL_INT or GL_DOUBLE.
         stride: The number of bytes to offset to the next vertex (used for interleaved array).
         pointer: The pointer to the vertex array.
        */
        
        glVertexPointer(2, GL_FLOAT, 0, &vtxArray[0]);
        glEnableClientState(GL_VERTEX_ARRAY);
        glColorPointer(4, GL_FLOAT, 0, &clrArray[0]);
        glEnableClientState(GL_COLOR_ARRAY);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); // number of vertexs/colours
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        
        ofPopMatrix();
        /*
         ofMesh temp;
         temp.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
         temp.addVertex( ofPoint(100,100) );
         temp.addColor(ofColor::pink);
         temp.addVertex( ofPoint(200,100) );
         temp.addColor(ofColor::pink);
         temp.addVertex( ofPoint(100,200) );
         temp.addColor(ofColor::yellow);
         temp.addVertex( ofPoint(200,200) );
         temp.addColor(ofColor::yellow);
         temp.draw();
         
         */
    }
};

#endif /* shapeGradientRect_h */
