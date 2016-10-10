/**
@file rgbMatrix.c
*/


#include "rgbMatrix.h"

void setColor(color *color,const uint r, const uint g, const uint b){
	color->r=r;
	color->g=g;
	color->b=b;
}


/*
matrix est initialisé par defaut a 0
taille w et h passé en paramètres
color par defaut BLANC  (r,g,b=0)

*/
void rgbInit(rgbMatrix *rgbM,const ulong w, const ulong h){
	ulong i=0,j=0;
	color Color;

	rgbM->width=w;
	rgbM->height=h;
	
	setColor(&Color,0,0,0);

	for(i=0;i<w;i++){
			rgbM->matrix[i]=malloc(h*sizeof(color));		
	}	
	

	for(i=0;i<w;i++){
		for(j=0;j<h;j++){			
			rgbM->matrix[i][j]=Color;		
		}
	}	
	

}

void rgbFree(rgbMatrix *rgbM){
	rgbM->width=0;
	rgbM->height=0;
	free(rgbM->matrix);
}


ulong rgbGetWidth(const rgbMatrix *rgbM){
	return rgbM->width;
}

void rgbSetWidth(rgbMatrix *rgbM, const ulong w){
	rgbM->width=w;
}




ulong rgbGetHeight(const rgbMatrix *rgbM){
	return rgbM->height;
}

void rgbSetHeight(rgbMatrix *rgbM,const ulong h){
	rgbM->height=h;
}




color rgbGetColorXY(const rgbMatrix *rgbM,const ulong w,const ulong h){
	return rgbM->matrix[h][w];
} 

void rgbSetColorXY(const rgbMatrix *rgbM,const ulong w,const ulong h,const color c){
	rgbM->matrix[h][w]=c;
} 
 
