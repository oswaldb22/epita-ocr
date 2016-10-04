/* 
	bwMatrix.h

	TODO : Complete header

	Black&White matrix
	Structure of a matrix containing 0 and 1 only 
	This is used to represent black&white images as data

	Disposition :

		w i d t h
	h
	e   0 1 0 0 1
	i   0 1 0 0 0	
	g   1 1 1 1 0
	h   0 1 1 0 1
	t   1 0 0 1 1

	/!\ Be careful when calling matrix[x][y] to not mix up height and width ! /!\

*/

/* Matrix containing only 0 and 1 */
struct bwMatrix
{
	unsigned long width;	//width of the matrix
	unsigned long height;	//height of the matrix
	unsigned bool** matrix;
};