//
//  shapeHexagon.h
//  9_ofTessaltor_howto
//
//  Created by alp tugan on 5.08.2019.
//

#ifndef shapeHexagon_h
#define shapeHexagon_h

#include "ofMain.h"

typedef enum {POINTY, FLAT} shapeHexTypes;


class shapeHexagon {
private:
    shapeHexTypes type;       // Hexagon drawing style
    ofPolyline hex;           // Polyline for hex stroke
    ofMesh hexMesh;           // Mesh for hex to fill inside
    ofTessellator tess;       // Tessalator to create mesh from polyline
    ofColor strokeColor;      // Hex stroke Color
    ofColor fillColor;        // Hex fill color
    glm::vec3 pos;            // Position on screen
    vector<glm::vec3> hVerts; // Hexagon vertices (corner coordinates)
    
    int hexW,                 // Hexagon width
        hexH,                 // Hexagon height
        hexHDist,             // Horizontal corner distance to calculate total width
        hexVDist,             // Vertical corner distance to calculate total height
        size,                 // hexagon edge length
        strokeSize;           // Stroke size
    
    int smoothVal;            // Corner radius
    
    bool isDebug;             // Enable Debugging
    
public:
    //---------------------------------------------------------------------
    // GETTERS & SETTERS
    //---------------------------------------------------------------------
    void setPos(int _x, int _y, int _z = 0) {
        pos = glm::vec3(_x, _y, _z);
        generateHexagon(pos, size, type);
    }
    
    void setFillColor(ofColor _c) {
        fillColor = _c;
    }
    
    void setStrokeColor(ofColor _c) {
        strokeColor = _c;
    }
    
    void setStrokeSize(int _s) {
        strokeSize = _s;
    }
    
    void setDrawingType(shapeHexTypes _t) {
        type = _t;
        generateHexagon(pos, size, type);
    }
    
    void setSize(int _s) {
        size = _s;
        generateHexagon(pos, size, type);
    }
    
    void setRoundness(int _r) {
        smoothVal = _r;
        generateHexagon(pos, size, type);
    }
    
    void setDebug(bool _d) {
        isDebug = _d;
    }
    
    int getWidth() {
        return hexW;
    }
    
    int getHeight() {
        return hexH;
    }
    
    glm::vec3 getPos() {
        return pos;
    }
    
    //---------------------------------------------------------------------
    // SETUP
    //---------------------------------------------------------------------
    void setup(glm::vec3 _pos, int _size = 80, shapeHexTypes _hexType = FLAT) {
        fillColor   = ofColor(255, 204, 0, 255);
        strokeColor = ofColor(25, 20, 0);
        strokeSize  = 2;
        smoothVal   = 0;
        
        isDebug     = false;
        
        generateHexagon(_pos, _size, _hexType);  // Generate hexagon
    }
    
    //---------------------------------------------------------------------
    // DRAW
    //---------------------------------------------------------------------
    void draw() {
        ofPushStyle();
        ofSetColor(fillColor);
        hexMesh.draw();              // Draw Hex Mesh Filled
        
        
        if(strokeSize != 0)
        {
            ofPushStyle();
            ofSetLineWidth(strokeSize);  // line thickness
            ofSetColor(strokeColor);     // Stroke Color
            hex.draw();                  // Draw stroke
            ofPopStyle();
        }
        
        if( isDebug ) {
            ofSetLineWidth(1);
            ofSetColor(255,0,0);
            ofNoFill();
            ofDrawRectangle(pos.x - hexW * 0.5,pos.y - hexH * 0.5, hexW, hexH);
            ofFill();
            ofDrawCircle(pos.x, pos.y, 3);
        }
        
        
        ofPopStyle();
    }
    
private:
    //---------------------------------------------------------------------
    // GENERATE HEXAGON SIDES
    // Reference : https://www.redblobgames.com/grids/hexagons/
    //---------------------------------------------------------------------
    void generateHexagon(glm::vec3 _pos, int _size, shapeHexTypes _hexType) {
        pos       = _pos;
        size      = _size;
        type      = _hexType;
        
        hVerts.clear();
        for (int i = 0; i < 6; i++) {
            hVerts.push_back(getHexCoord(pos, size, i, type));
        }
        
        // Calculate width and height
        if( type == FLAT) {
            hexW = 2 * size;
            hexH = sqrt(3) * size;
            
            // The horizontal distance between adjacent hexagon centers is w * 3/4.
            // The vertical distance between adjacent hexagon centers is h.
            hexHDist = hexW * (3 / 4);
            hexVDist = hexH;
            
        }else if(type == POINTY) {
            hexW = sqrt(3) * size;
            hexH = 2 * size;
            
            // The horizontal distance between adjacent hexagon centers is w.
            // The vertical distance between adjacent hexagon centers is h * 3/4.
            hexHDist = hexW;
            hexVDist = hexH * (3 / 4);
        }
        
        hex.clear();
        hex.addVertices(hVerts);
        hex.close();
        
        if( smoothVal != 0 )
        {
            hex = hex.getResampledBySpacing(smoothVal + 1);
            hex = hex.getSmoothed(smoothVal);
        }
        
        
        tess.tessellateToMesh(hex, ofPolyWindingMode::OF_POLY_WINDING_ODD, hexMesh, true);
    }
    
    //---------------------------------------------------------------------
    // CALCULATE CORNER COORDINATES
    // Reference : https://www.redblobgames.com/grids/hexagons/
    //---------------------------------------------------------------------
    glm::vec3 getHexCoord(glm::vec3 _center, float _size, int i, shapeHexTypes _hexType)
    {
        float _angle_deg = 60 * i - (_hexType == FLAT ? 0 : 30);
        float _angle_rad = PI / 180 * _angle_deg;
        
        return glm::vec3 (_center.x + _size * cos(_angle_rad),
                          _center.y + _size * sin(_angle_rad),0);
    }
};

#endif /* shapeHexagon_h */
