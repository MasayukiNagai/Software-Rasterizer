#include "Model.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

Model::Model(){
}

int Model::numTriangles(){
    return triangles.size();
}

Triangle3D Model::operator[](int i){
    return triangles[i];
}

void Model::Transform(Matrix4 pMatrix){
    for(int i = 0; i < triangles.size(); i++){
        triangles[i].Transform(pMatrix);
    }
}

void Model::ReadFromOBJFile(string filepath, Color pFillColor){
    ifstream myFile(filepath);
    if(myFile.is_open()){
        string line;
        while(getline(myFile, line)){
            istringstream s(line);
            string symbol;
            vector<string> list;
            bool vertex = false;
            bool face = false;
            int i = 0;
            float x, y, z;
            Vector4 v0, v1, v2;
            int v0_index, v1_index, v2_index;
            while(getline(s, symbol, ' ')){
                if(symbol != " "){
                    list.push_back(symbol);
                }
                if(symbol == "v"){
                    vertex = true;
                    face = false;
                }
                else if(symbol == "f"){
                    vertex = false;
                    face = true;
                }
                else if(vertex){
                    if(i == 1) x = atof(symbol.c_str());
                    else if(i == 2) y = atof(symbol.c_str());
                    else if (i == 3) z = atof(symbol.c_str());
                }
                else if(face){
                    if(i == 1){
                        v0_index = atoi(symbol.c_str()) - 1;
                        v0 = vertices[v0_index];
                    } 
                    else if(i == 2){
                        v1_index = atoi(symbol.c_str()) - 1;
                        v1 = vertices[v1_index];
                    }
                    else if(i == 3){
                        v2_index = atoi(symbol.c_str()) - 1;
                        v2 = vertices[v2_index];
                    } 
                }
                i++;
            }
            if(vertex){
                Vector4 vec = Vector4(x, y, z, 1.0);
                vertices.push_back(vec);
                cout << "v " << x << " " << y << " " << z << endl; 
            }
            else if(face){
                Triangle3D triangle(v0, v1, v2, pFillColor, pFillColor, pFillColor);
                triangles.push_back(triangle);
                // cout << "f " << v0_index << " " << v1_index << " " << v2_index << endl;
            }
        }
        myFile.close();
    }
}


