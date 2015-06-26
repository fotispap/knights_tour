#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int SIZE=8;
typedef unsigned char cell;

int moves_x[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int moves_y[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

void print_array(char **array, int m, int n) {
	int i,j;
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			printf(" %d ", array[i][j]);
		}
		printf("\n");
	}
}

void print_usage() {
	printf("Usage: ./knights <N>\nWhere <N> is the maximum length of the board\n");

}

int calculate_moves(int i, int j, int m, int n) {
	int k=0;
	int moves=0;
	for(k=0;k<8;k++) {
		int x = i+moves_x[k];
		int y = j+moves_y[k];
		if(x >= 0 && y >= 0 && x < m && y < n ) {
			 printf("From position (%d,%d), move %d,%d is legal! ( %d , %d) - board is: %d x %d \n",i,j,moves_x[k],moves_y[k],x,y,m,n);
			 moves++; 
		} else {
			 printf("From position (%d,%d), move %d,%d is illegal! ( %d , %d) - board is: %d x %d \n",i,j,moves_x[k],moves_y[k],x,y,m,n);
		}
	}
	return moves;
}

int solution_exists(int m, int n) {
	if( ((m%2)) && ((n%2)) ) return 0;
	if( (m==1) || (m==2) || (m==4) ) return 0;
	if( (m==3) && ( (n==4) || (n==6) || (n==8))) return 0;
	return 1;
}

char** initialize_array(char **board, int m, int n) {
	int i,j,k;
	board = (char**) malloc(sizeof(char*)*m);

	for(i=0;i<m;i++) {
		board[i] = (char*) malloc(sizeof(char)*n);
		//memset(*(board+i), 0, n);
	}
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			board[i][j] = calculate_moves(i,j,m,n) ;
		
		}
	}
	return board;
}

int main(int argc, char** argv) {
	int i,j, ii,jj, step=0;
    char **board;

	if(!(argc==2)) {
		print_usage();
		exit(0);
	}
	int N = atoi(argv[1]);
	printf("Calculating all possible boards with maximum length %d ...\n",N);
	
	for(i=0;i<N;i++) {
		int n = i+1;

		for(j=0;j<n;j++) {
			int m = j+1;
			if(solution_exists(m,n)) {

				board = initialize_array(board,m,n);
				printf("Board %d x %d has solution\n", m, n);
				//initialize(m,n, a, b);
				print_array(board,m,n);
			} else {
				printf("Board %d x %d does not have solution\n", m, n);
			}
			
		}
	}
	

	
//	print_array(array);
//	printf("Hello World\n");
	return 0;
}


