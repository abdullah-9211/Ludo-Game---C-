//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================


/*----------------------------------------LUDO PROJECT------------------------------------------------------------*/

//NAME: Abdullah Umar
//Roll Number: 20I-0444





#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*------------GLOBAL VARIABLES--------------*/

int players, check = 0, proceed = 0, done = 0, col_check = 0;
int color1 = 0, color2 = 0, color3 = 0, color4 = 0, complete = 0, game = 0;
int color[4], clear = 0;
int dice_num, temp_turn = 4, turn_start = 0, turn;
int turn1 = 0, turn2 = 0, turn3 = 0, turn4 = 0;
int disc_pos[2], pos1[2], pos2[2], pos3[2], pos4[2];
int next_turn = 0, turn_val1;
string name1, name2, name3, name4;
int home[4][4] = {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
int initial[5][5][3];
int six = 0;
int piece_num, kill1, kill2, kill3, kill4;
int movement = 0;
int block[5][3][3];
int board_coords[5][5][3];
int pieces[5][5][4];
int temp[4];
int piece_count1 = 4, piece_count2 = 4, piece_count3 = 4, piece_count4 = 4;
int players_left;
int win1 = 0, win2 = 0, win3 = 0, win4 = 0;
int score1 = 0, score2 = 0, score3 = 0, score4 = 0;





/*------------GLOBAL VARIABLES--------------*/

//Function to display Board on screen
void Board()
{
	//Background
	DrawRectangle(0, 0, 1020, 840, colors[NAVY]);

	//Board	
	DrawRectangle( 130, 50, 750, 750, colors[WHITE]);
	
	//Colour Squares
	DrawRectangle(130, 500, 300, 300, colors[BLUE]);
	DrawRectangle(580, 500, 300, 300, colors[OLIVE]);
	DrawRectangle(580, 50, 300, 300, colors[GREEN]);
	DrawRectangle(130, 50, 300,300 ,colors[RED]);
	
	//Triangles in center
	DrawTriangle(428, 502, 428, 348, 500, 420, colors[BLUE]);
	DrawTriangle(428, 502, 584, 502, 500, 420, colors[OLIVE]);
	DrawTriangle(584, 502, 584, 348, 500, 420, colors[GREEN]);
	DrawTriangle(428, 348, 584, 348, 500, 420, colors[RED]);
	
	//Lines for division of squares between Y and B
	DrawLine(478, 800, 478, 500, 0.5, colors[BLACK]);
	DrawLine(530, 800, 530, 500, 0.5, colors[BLACK]);
	DrawLine(428, 750, 580, 750, 0.5, colors[BLACK]);
	DrawLine(428, 700, 580, 700, 0.5, colors[BLACK]);
	DrawLine(428, 650, 580, 650, 0.5, colors[BLACK]);
	DrawLine(428, 600, 580, 600, 0.5, colors[BLACK]);
	DrawLine(428, 550, 580, 550, 0.5, colors[BLACK]);
	DrawLine(428, 500, 582, 500, 0.5, colors[BLACK]);

	//Lines for division of squares between Y and G
	DrawLine(880, 450, 584, 450, 0.5, colors[BLACK]);
	DrawLine(880, 400, 584, 400, 0.5, colors[BLACK]);
	DrawLine(830, 500, 830, 348, 0.5, colors[BLACK]);
	DrawLine(780, 500, 780, 348, 0.5, colors[BLACK]);
	DrawLine(730, 500, 730, 348, 0.5, colors[BLACK]);
	DrawLine(680, 500, 680, 348, 0.5, colors[BLACK]);
	DrawLine(630, 500, 630, 348, 0.5, colors[BLACK]);
	DrawLine(583, 500, 583, 348, 0.5, colors[BLACK]);

	//Lines for division of squares between G and R
	DrawLine(478, 348, 478, 50, 0.5, colors[BLACK]);
	DrawLine(528, 348, 528, 50, 0.5, colors[BLACK]);
	DrawLine(428, 100, 580, 100, 0.5, colors[BLACK]);
	DrawLine(428, 150, 580, 150, 0.5, colors[BLACK]);
	DrawLine(428, 200, 580, 200, 0.5, colors[BLACK]);
	DrawLine(428, 250, 580, 250, 0.5, colors[BLACK]);
	DrawLine(428, 300, 580, 300, 0.5, colors[BLACK]);
	DrawLine(428, 348, 580, 348, 0.5, colors[BLACK]);
	
	//Lines for division of squares between R and B
	DrawLine(130, 450, 428, 450, 0.5, colors[BLACK]);
	DrawLine(130, 400, 428, 400, 0.5, colors[BLACK]);
	DrawLine(180, 500, 180, 348, 0.5, colors[BLACK]);
	DrawLine(230, 500, 230, 348, 0.5, colors[BLACK]);
	DrawLine(280, 500, 280, 348, 0.5, colors[BLACK]);
	DrawLine(330, 500, 330, 348, 0.5, colors[BLACK]);
	DrawLine(380, 500, 380, 348, 0.5, colors[BLACK]);
	DrawLine(430, 500, 430, 348, 0.5, colors[BLACK]);
	
	//Internal big square of all boxes
	DrawRectangle(170, 540, 220, 220, colors[WHITE]);
	DrawRectangle(625, 540, 215, 220, colors[WHITE]);
	DrawRectangle(170, 90, 215, 220, colors[WHITE]);
	DrawRectangle(625, 90, 220, 220, colors[WHITE]);
	
	//Internal small squares of Blue
	DrawSquare(200, 680, 50, colors[BLUE]);
	DrawSquare(305, 680, 50, colors[BLUE]);
	DrawSquare(200, 570, 50, colors[BLUE]);
	DrawSquare(305, 570, 50, colors[BLUE]);
	
	//Internal small squares of Yellow
	DrawSquare(760, 680, 50 ,colors[OLIVE]);
	DrawSquare(660, 680, 50 ,colors[OLIVE]);
	DrawSquare(760, 570, 50 ,colors[OLIVE]);
	DrawSquare(660, 570, 50 ,colors[OLIVE]);
	
	//Internal small squares of Green
	DrawSquare(760, 230, 50, colors[GREEN]);
	DrawSquare(660, 230, 50, colors[GREEN]);
	DrawSquare(760, 120, 50, colors[GREEN]);
	DrawSquare(660, 120, 50, colors[GREEN]);
	
	//Internal small squares of Red
	DrawSquare(200, 230, 50, colors[RED]);
	DrawSquare(305, 230, 50, colors[RED]);
	DrawSquare(200, 120, 50, colors[RED]);
	DrawSquare(305, 120, 50, colors[RED]);
	
	//Filling coloured blocks of blue side
	DrawSquare(180, 451, 50, colors[BLUE]);
	DrawSquare(180, 401, 50, colors[BLUE]);
	DrawSquare(230, 401, 50, colors[BLUE]);
	DrawRectangle(230, 349, 50, 52, colors[GRAY]);
	DrawSquare(280, 401, 50, colors[BLUE]);
	DrawSquare(330, 401, 50, colors[BLUE]);
	DrawSquare(380, 401, 50, colors[BLUE]);
	
	//Filling coloured blocks of Yellow side
	DrawRectangle(530, 701, 51, 50, colors[OLIVE]);
	DrawRectangle(478, 701, 52, 50, colors[OLIVE]);
	DrawRectangle(478, 651, 52, 50, colors[OLIVE]);
	DrawRectangle(428, 651, 50, 50, colors[GRAY]);
	DrawRectangle(478, 601, 52, 50, colors[OLIVE]);
	DrawRectangle(478, 551, 52, 50, colors[OLIVE]);
	DrawRectangle(478, 501, 52, 50, colors[OLIVE]);
	
	//Filling coloured blocks of green side
	DrawRectangle(780, 349, 50, 52, colors[GREEN]);
	DrawRectangle(780, 401, 50, 50, colors[GREEN]);
	DrawRectangle(730, 401, 50, 50, colors[GREEN]);
	DrawRectangle(730, 451, 50, 50, colors[GRAY]);
	DrawRectangle(680, 401, 50, 50, colors[GREEN]);
	DrawRectangle(630, 401, 50, 50, colors[GREEN]);
	DrawRectangle(584, 401, 46, 50, colors[GREEN]);
	
	//Filling coloured blocks of red side
	DrawRectangle(429, 101, 49, 50, colors[RED]);
	DrawRectangle(478, 101, 50, 50, colors[RED]);
	DrawRectangle(478, 151, 50, 50, colors[RED]);
	DrawRectangle(528, 151, 53, 50, colors[GRAY]);
	DrawRectangle(478, 201, 50, 50, colors[RED]);
	DrawRectangle(478, 251, 50, 50, colors[RED]);
	DrawRectangle(478, 301, 50, 48, colors[RED]);
	
	//Pieces for blue
	DrawCircle(pieces[4][1][1], pieces[4][1][2], 22, colors[BLACK]);
	DrawCircle(pieces[4][1][1], pieces[4][1][2], 20, colors[BLUE]);
	DrawCircle(pieces[4][1][1], pieces[4][1][2], 11, colors[BLACK]);
	DrawCircle(pieces[4][1][1], pieces[4][1][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[4][2][1], pieces[4][2][2], 22, colors[BLACK]);
	DrawCircle(pieces[4][2][1], pieces[4][2][2], 20, colors[BLUE]);
	DrawCircle(pieces[4][2][1], pieces[4][2][2], 11, colors[BLACK]);
	DrawCircle(pieces[4][2][1], pieces[4][2][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[4][3][1], pieces[4][3][2], 22, colors[BLACK]);
	DrawCircle(pieces[4][3][1], pieces[4][3][2], 20, colors[BLUE]);
	DrawCircle(pieces[4][3][1], pieces[4][3][2], 11, colors[BLACK]);
	DrawCircle(pieces[4][3][1], pieces[4][3][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[4][4][1], pieces[4][4][2], 22, colors[BLACK]);
	DrawCircle(pieces[4][4][1], pieces[4][4][2], 20, colors[BLUE]);
	DrawCircle(pieces[4][4][1], pieces[4][4][2], 11, colors[BLACK]);
	DrawCircle(pieces[4][4][1], pieces[4][4][2], 9, colors[WHITE]);
	
	
	//Pieces for Yellow
	DrawCircle(pieces[3][1][1], pieces[3][1][2], 22, colors[BLACK]);
	DrawCircle(pieces[3][1][1], pieces[3][1][2], 20, colors[OLIVE]);
	DrawCircle(pieces[3][1][1], pieces[3][1][2], 11, colors[BLACK]);
	DrawCircle(pieces[3][1][1], pieces[3][1][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[3][2][1], pieces[3][2][2], 22, colors[BLACK]);
	DrawCircle(pieces[3][2][1], pieces[3][2][2], 20, colors[OLIVE]);
	DrawCircle(pieces[3][2][1], pieces[3][2][2], 11, colors[BLACK]);
	DrawCircle(pieces[3][2][1], pieces[3][2][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[3][3][1], pieces[3][3][2], 22, colors[BLACK]);
	DrawCircle(pieces[3][3][1], pieces[3][3][2], 20, colors[OLIVE]);
	DrawCircle(pieces[3][3][1], pieces[3][3][2], 11, colors[BLACK]);
	DrawCircle(pieces[3][3][1], pieces[3][3][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[3][4][1], pieces[3][4][2], 22, colors[BLACK]);
	DrawCircle(pieces[3][4][1], pieces[3][4][2], 20, colors[OLIVE]);
	DrawCircle(pieces[3][4][1], pieces[3][4][2], 11, colors[BLACK]);
	DrawCircle(pieces[3][4][1], pieces[3][4][2], 9, colors[WHITE]);
	
	
	//Pieces for Green
	DrawCircle(pieces[2][1][1], pieces[2][1][2], 22, colors[BLACK]);
	DrawCircle(pieces[2][1][1], pieces[2][1][2], 20, colors[GREEN]);
	DrawCircle(pieces[2][1][1], pieces[2][1][2], 11, colors[BLACK]);
	DrawCircle(pieces[2][1][1], pieces[2][1][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[2][2][1] , pieces[2][2][2], 22, colors[BLACK]);
	DrawCircle(pieces[2][2][1] , pieces[2][2][2], 20, colors[GREEN]);
	DrawCircle(pieces[2][2][1] , pieces[2][2][2], 11, colors[BLACK]);
	DrawCircle(pieces[2][2][1] , pieces[2][2][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[2][3][1], pieces[2][3][2], 22, colors[BLACK]);
	DrawCircle(pieces[2][3][1], pieces[2][3][2], 20, colors[GREEN]);
	DrawCircle(pieces[2][3][1], pieces[2][3][2], 11, colors[BLACK]);
	DrawCircle(pieces[2][3][1], pieces[2][3][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[2][4][1], pieces[2][4][2], 22, colors[BLACK]);
	DrawCircle(pieces[2][4][1], pieces[2][4][2], 20, colors[GREEN]);
	DrawCircle(pieces[2][4][1], pieces[2][4][2], 11, colors[BLACK]);
	DrawCircle(pieces[2][4][1], pieces[2][4][2], 9, colors[WHITE]);
	
	
	//Pieces for Red
	DrawCircle(pieces[1][1][1], pieces[1][1][2], 22, colors[BLACK]);
	DrawCircle(pieces[1][1][1], pieces[1][1][2], 20, colors[RED]);
	DrawCircle(pieces[1][1][1], pieces[1][1][2], 11, colors[BLACK]);
	DrawCircle(pieces[1][1][1], pieces[1][1][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[1][2][1], pieces[1][2][2], 22, colors[BLACK]);
	DrawCircle(pieces[1][2][1], pieces[1][2][2], 20, colors[RED]);
	DrawCircle(pieces[1][2][1], pieces[1][2][2], 11, colors[BLACK]);
	DrawCircle(pieces[1][2][1], pieces[1][2][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[1][3][1], pieces[1][3][2], 22, colors[BLACK]);
	DrawCircle(pieces[1][3][1], pieces[1][3][2], 20, colors[RED]);
	DrawCircle(pieces[1][3][1], pieces[1][3][2], 11, colors[BLACK]);
	DrawCircle(pieces[1][3][1], pieces[1][3][2], 9, colors[WHITE]);
	
	DrawCircle(pieces[1][4][1], pieces[1][4][2], 22, colors[BLACK]);
	DrawCircle(pieces[1][4][1], pieces[1][4][2], 20, colors[RED]);
	DrawCircle(pieces[1][4][1], pieces[1][4][2], 11, colors[BLACK]);
	DrawCircle(pieces[1][4][1], pieces[1][4][2], 9, colors[WHITE]);
	
	
	//Making Dice
	DrawRoundRect(915, 400, 74, 74, colors[BLACK], 0);
	DrawRoundRect(915, 400, 70, 70, colors[MAROON], 0); 
	DrawString(885, 370, "*Press Space", colors[WHITE]); 
	DrawString(915, 340, "to Roll", colors[WHITE]); 
	

}

//For initial menu
void StartMenu()
{
	//Designing initial menu till asking for number of players
	DrawString(400, 800, "LUDO GAME", colors[CRIMSON]);
	DrawString(100, 700, "Please select the number of players:", colors[OLIVE]);
	DrawCircle(150, 600, 60, colors[AQUA]);
	DrawCircle(450, 600, 60, colors[AQUA]);
	DrawCircle(750, 600, 60, colors[AQUA]);
	DrawString(145, 595, "2", colors[BLACK]);
	DrawString(445, 595, "3", colors[BLACK]);
	DrawString(745, 595, "4", colors[BLACK]);

}

//For printing dots on dice
void Dice(int num)
{
	//Switch for different numbers of turn
	switch (num)
	{
		case 1:
			DrawCircle(950, 435, 10, colors[BLACK]);
			DrawCircle(950, 435, 8, colors[WHITE]);
			break; 
		case 2:
			DrawCircle(963, 446, 10, colors[BLACK]);
			DrawCircle(963, 446, 8, colors[WHITE]);
			
			DrawCircle(938, 420, 10, colors[BLACK]);
			DrawCircle(938, 420, 8, colors[WHITE]);
			break; 
		case 3:
			DrawCircle(973, 456, 10, colors[BLACK]);
			DrawCircle(973, 456, 8, colors[WHITE]);
			
			DrawCircle(950, 435, 10, colors[BLACK]);
			DrawCircle(950, 435, 8, colors[WHITE]);
			
			DrawCircle(928, 410, 10, colors[BLACK]);
			DrawCircle(928, 410, 8, colors[WHITE]);
			break; 
		case 4:
			DrawCircle(973, 456, 10, colors[BLACK]);
			DrawCircle(973, 456, 8, colors[WHITE]);
				
			DrawCircle(928, 456, 10, colors[BLACK]);
			DrawCircle(928, 456, 8, colors[WHITE]);
			
			DrawCircle(973, 410, 10, colors[BLACK]);
			DrawCircle(973, 410, 8, colors[WHITE]);
				
			DrawCircle(928, 410, 10, colors[BLACK]);
			DrawCircle(928, 410, 8, colors[WHITE]);
			break; 
		case 5:
			DrawCircle(973, 456, 10, colors[BLACK]);
			DrawCircle(973, 456, 8, colors[WHITE]);
				
			DrawCircle(928, 456, 10, colors[BLACK]);
			DrawCircle(928, 456, 8, colors[WHITE]);
			
			DrawCircle(973, 410, 10, colors[BLACK]);
			DrawCircle(973, 410, 8, colors[WHITE]);
			
			DrawCircle(950, 435, 10, colors[BLACK]);
			DrawCircle(950, 435, 8, colors[WHITE]);
				
			DrawCircle(928, 410, 10, colors[BLACK]);
			DrawCircle(928, 410, 8, colors[WHITE]);
			break; 
		case 6:
			DrawCircle(973, 450, 10, colors[BLACK]);
			DrawCircle(973, 450, 8, colors[WHITE]);
				
			DrawCircle(928, 450, 10, colors[BLACK]);
			DrawCircle(928, 450, 8, colors[WHITE]);
			
			DrawCircle(973, 416, 10, colors[BLACK]);
			DrawCircle(973, 416, 8, colors[WHITE]);
			
			DrawCircle(950, 450, 10, colors[BLACK]);
			DrawCircle(950, 450, 8, colors[WHITE]);
			
			DrawCircle(950, 416, 10, colors[BLACK]);
			DrawCircle(950, 416, 8, colors[WHITE]);
				
			DrawCircle(928, 416, 10, colors[BLACK]);
			DrawCircle(928, 416, 8, colors[WHITE]);
			break;
		
	}


}


//To show whose turn it is
void ShowTurn()
{
	switch (turn)
	{
		case 1:
			DrawRectangle(pos1[0], pos1[1], 130, 40, colors[WHITE]);
			DrawString(pos1[0], pos1[1] + 10, "  Your Turn", colors[BLACK]);
			break;
		case 2:
			DrawRectangle(pos2[0], pos2[1], 130, 40, colors[WHITE]);
			DrawString(pos2[0], pos2[1] + 10, "  Your Turn", colors[BLACK]);
			break;
		case 3:
			DrawRectangle(pos3[0], pos3[1], 130, 40, colors[WHITE]);
			DrawString(pos3[0], pos3[1] + 10, "  Your Turn", colors[BLACK]);
			break;
		case 4:
			DrawRectangle(pos4[0], pos4[1], 130, 40, colors[WHITE]);
			DrawString(pos4[0], pos4[1] + 10, "  Your Turn", colors[BLACK]);
			break;
	
	}

}


//To change turns
void ChangeTurns()
{

	if (players == 4 && next_turn == 1)
	{
		cout<<turn<<endl;
		if (turn == 4)
		{
			turn = 3;
			next_turn = 0;
		}
		else if (turn == 3)
		{
			turn = 2;
			next_turn = 0;
		}
		else if (turn == 2)
		{
			turn = 1;
			next_turn = 0;
		}
		else if (turn == 1)
		{
			turn = 4;
			next_turn = 0;
		}
	
	}
	
	else if (players == 3 && next_turn == 1)
	{
		
		if (color1 != 1 && color2 != 1 && color3 != 1)
		{
			if (turn == 4)
			{
				turn = 3;
				next_turn = 0;
			}
			else if (turn == 3)
			{
				turn = 2;
				next_turn = 0;
			}
			else if (turn == 2)
			{
				turn = 4;
				next_turn = 0;
			}
			
		}
		else if (color1 != 2 && color2 != 2 && color3 != 2)
		{
			if (turn == 4)
			{
				turn = 3;
				next_turn = 0;
			}
			else if (turn == 3)
			{
				turn = 1;
				next_turn = 0;
			}
			else if (turn == 1)
			{
				turn = 4;
				next_turn = 0;
			}
		
		}
		else if (color1 != 3 && color2 != 3 && color3 != 3)
		{
			if (turn == 4)
			{
				turn = 2;
				next_turn = 0;
			}
			else if (turn == 2)
			{
				turn = 1;
				next_turn = 0;
			}
			else if (turn == 1)
			{
				turn = 4;
				next_turn = 0;
			}
		
		
		}
		
		else if (color1 != 4 && color2 != 4 && color3 != 4)
		{
			if (turn == 3)
			{
				turn = 2;
				next_turn = 0;
			}
			else if (turn == 2)
			{
				turn = 1;
				next_turn = 0;
			}
			else if (turn == 1)
			{
				turn = 3;
				next_turn = 0;
			}
		
		}
	
	}
	
	else if (players == 2 && next_turn == 1)
	{
		if (turn == color1)
		{
			turn = color2;
			next_turn = 0;
		}	
		else if (turn == color2)
		{
			turn = color1;
			next_turn = 0;
		}
	}
	
	six = 0;
	turn_val1 = 0;


}

//To kill pieces
void Kill()
{
	for (int goti_num1 = 1; goti_num1 <= 4; goti_num1++)
	{
		for (int player_num = 1; player_num <= 4; player_num++)
		{
			if (player_num != turn)
			{
				for (int goti_num2 = 1; goti_num2 <= 4; goti_num2++)
				{
					if ((pieces[turn][goti_num1][1] == pieces[player_num][goti_num2][1] && pieces[turn][goti_num1][2] == pieces[player_num][goti_num2][2]) && !(pieces[turn][goti_num1][1] == 452 && pieces[turn][goti_num1][2] == 125) && !(pieces[turn][goti_num1][1] == 252 && pieces[turn][goti_num1][2] == 375) && !(pieces[turn][goti_num1][1] == 202 && pieces[turn][goti_num1][2] == 475) && !(pieces[turn][goti_num1][1] == 452 && pieces[turn][goti_num1][2] == 675) && !(pieces[turn][goti_num1][1] == 552 && pieces[turn][goti_num1][2] == 725) && !(pieces[turn][goti_num1][1] == 752 && pieces[turn][goti_num1][2] == 475) && !(pieces[turn][goti_num1][1] == 802 && pieces[turn][goti_num1][2] == 375) && !(pieces[turn][goti_num1][1] == 552 && pieces[turn][goti_num1][2] == 175) && !(pieces[turn][goti_num1][1] == block[player_num][1][1] && pieces[turn][goti_num1][2] == block[player_num][1][2]) && !(pieces[turn][goti_num1][1] == block[player_num][2][1] && pieces[turn][goti_num1][2] == block[player_num][2][2]))
					
					{
						pieces[player_num][goti_num2][1] = initial[player_num][goti_num2][1];
						pieces[player_num][goti_num2][2] = initial[player_num][goti_num2][2];
						home[player_num - 1][goti_num2 - 1] = 1;
						
						//To check if colour has killed a piece
						if (turn == 1)
						{
							kill1 = 1;
							score1 += 10;
						}
						else if (turn == 2)
						{
							kill2 = 1;
							score2 += 10;
						}
						else if (turn == 3)
						{
							kill3 = 1;
							score3 += 10;
						}
						else if (turn == 4)
						{
							kill4 = 1;
							score4 += 10;
						}
						
						
						
					}
				
				}
			}

		
		}
	}



}

//for stack if two pieces of same colour overlap one another
void Stack()
{
	block[turn][1][1] = 0;
	block[turn][1][2] = 0;
	block[turn][2][1] = 0;
	block[turn][2][2] = 0;

	for (int goti1 = 1; goti1 <= 4; goti1++)
	{
		for (int goti2 = 1; goti2 <= 4; goti2++)
		{
			if (goti1 != goti2)
			{
				if (pieces[turn][goti1][1] == pieces[turn][goti2][1] && pieces[turn][goti1][2] == pieces[turn][goti2][2] && block[turn][1][1] != pieces[turn][goti1][1] && block[turn][1][2] != pieces[turn][goti1][2])
				{
					block[turn][1][1] = pieces[turn][goti1][1];
					block[turn][1][2] = pieces[turn][goti1][2];
					
					if (turn == 1)
					{
						score1 += 2;
					}
					else if (turn == 2)
					{
						score2 += 2;
					}
					else if (turn == 3)
					{
						score3 += 2;
					}
					else if (turn == 4)
					{
						score4 += 2;
					}
				
				}
				else if (pieces[turn][goti1][1] == pieces[turn][goti2][1] && pieces[turn][goti1][2] == pieces[turn][goti2][2])
				{
					block[turn][2][1] = pieces[turn][goti1][1];
					block[turn][2][2] = pieces[turn][goti1][2];
					
					if (turn == 1)
					{
						score1 += 2;
					}
					else if (turn == 2)
					{
						score2 += 2;
					}
					else if (turn == 3)
					{
						score3 += 2;
					}
					else if (turn == 4)
					{
						score4 += 2;
					}
				
				}
				
				
			}
		}
	
	}




}


//Conditions when a piece completes its cycle and is finished (For every colour)
void Win()
{
	if (turn == 1)
	{
		if (pieces[1][piece_num][1] == 502 && pieces[1][piece_num][2] == 375)
		{
			pieces[1][piece_num][1] = 10000;
			pieces[1][piece_num][2] = 10000;
			board_coords[1][piece_num][1] = 10000;
			board_coords[1][piece_num][2] = 10000;
			
			piece_count1--;
			
			if (piece_count1 == 0)
			{
				players_left--;
			}
			home[0][piece_num - 1] = 1;
			
			win1 = 1;
		}
	}

	else if (turn == 2)
	{
		if (pieces[2][piece_num][1] == 552 && pieces[2][piece_num][2] == 425)
		{
			pieces[2][piece_num][1] = 10000;
			pieces[2][piece_num][2] = 1000;
			board_coords[2][piece_num][1] = 10000;
			board_coords[2][piece_num][2] = 1000;
			
			piece_count2--;
			
			if (piece_count2 == 0)
			{
				players_left--;
			}
			
			home[1][piece_num - 1] = 1;
			
			win2 = 1;
		}
	}
	
	
	else if (turn == 3)
	{
		if (pieces[3][piece_num][1] == 502 && pieces[3][piece_num][2] == 475)
		{
			pieces[3][piece_num][1] = 10000;
			pieces[3][piece_num][2] = 100;
			board_coords[3][piece_num][1] = 10000;
			board_coords[3][piece_num][2] = 100;
			
			piece_count3--;
			
			if (piece_count3 == 0)
			{
				players_left--;
			}
			
			home[2][piece_num - 1] = 1;
			
			win3 = 1;
		}
	}
	
	else if (turn == 4)
	{
		if (pieces[4][piece_num][1] == 452 && pieces[4][piece_num][2] == 425)
		{
			pieces[4][piece_num][1] = 10000;
			pieces[4][piece_num][2] = 10;
			board_coords[4][piece_num][1] = 10000;
			board_coords[4][piece_num][2] = 10;
			
			piece_count4--;
			
			if (piece_count4 == 0)
			{
				players_left--;
			}
			
			home[3][piece_num - 1] = 1;
			
			win4 = 1;
		}
	}


}





//For movement of the pieces of every colour 
void Movement()
{						/*Specific turning points have been hardcoded so that turn is made by piece on path*/
	
	//For red pieces
	if (turn == 1)
	{
		
		
						/*---------------------DIRECTIONS: 1 = upward, 2 = left, 3 = down, 4 = right-------------------------*/
		//if (movement == 1)
		//{
			for (int i = 0; i < turn_val1; i++)
			{
				//Incrementing score for movement
				score1++;
				
				if (pieces[1][piece_num][3] == 1)
				{
					if (pieces[1][piece_num][1] == 452 && pieces[1][piece_num][2] == 325)
					{
						pieces[1][piece_num][1] -= 50;
						pieces[1][piece_num][2] += 50;
						board_coords[1][piece_num][1] = 402;
						board_coords[1][piece_num][2] = 465;
						pieces[1][piece_num][3] = 2;
					}
					else if (pieces[1][piece_num][1] == 152 && pieces[1][piece_num][2] == 475)
					{
						pieces[1][piece_num][1] += 50;
						board_coords[1][piece_num][1] = 204;
						board_coords[1][piece_num][2] = 364;
						pieces[1][piece_num][3] = 4;
					}
					else if (pieces[1][piece_num][1] == 452 && pieces[1][piece_num][2] == 775)
					{
						pieces[1][piece_num][1] += 50;
						board_coords[1][piece_num][1] = 503;
						board_coords[1][piece_num][2] = 63;
						pieces[1][piece_num][3] = 4;
					}
					else
					{
						pieces[1][piece_num][2] += 50;
						board_coords[1][piece_num][2] -= 50;
						Win();
					}
					
				}
				
				else if (pieces[1][piece_num][3] == 2)
				{
					if (pieces[1][piece_num][1] == 152 && pieces[1][piece_num][2] == 375)
					{
						pieces[1][piece_num][2] += 50;
						board_coords[1][piece_num][1] = 154;
						board_coords[1][piece_num][2] = 414;
						pieces[1][piece_num][3] = 1;
					}
					else if (pieces[1][piece_num][1] == 602 && pieces[1][piece_num][2] == 375)
					{
						pieces[1][piece_num][1] -= 50;
						pieces[1][piece_num][2] -= 50;
						board_coords[1][piece_num][1] = 554;
						board_coords[1][piece_num][2] = 514;
						pieces[1][piece_num][3] = 3;
					
					}
					//To enter home according to condition
					else if (pieces[1][piece_num][1] == 502 && pieces[1][piece_num][2] == 75)
					{
						if (kill1 == 1)
						{
							pieces[1][piece_num][2] += 50;
							board_coords[1][piece_num][1] = 502;
							board_coords[1][piece_num][2] = 715;
							pieces[1][piece_num][3] = 1;
							score1 += 15;
						}
						else
						{
							pieces[1][piece_num][1] -= 50;
							board_coords[1][piece_num][1] -= 50;
							pieces[1][piece_num][3] = 1;
						}
					
					}
					else
					{
						pieces[1][piece_num][1] -= 50;
						board_coords[1][piece_num][1] -= 50;
					}
					
				}
				
				else if (pieces[1][piece_num][3] == 3)
				{
					if (pieces[1][piece_num][1] == 552 && pieces[1][piece_num][2] == 525)
					{
						pieces[1][piece_num][1] += 50;
						pieces[1][piece_num][2] -= 50;
						board_coords[1][piece_num][1] = 604;
						board_coords[1][piece_num][2] = 363;
						pieces[1][piece_num][3] = 4;
					
					}
					else if (pieces[1][piece_num][1] == 852 && pieces[1][piece_num][2] == 375)
					{
						pieces[1][piece_num][1] -= 50;
						board_coords[1][piece_num][1] = 804;
						board_coords[1][piece_num][2] = 463;
						pieces[1][piece_num][3] = 2;
					
					}
					else if (pieces[1][piece_num][1] == 552 && pieces[1][piece_num][2] == 75)
					{
						pieces[1][piece_num][1] -= 50;
						board_coords[1][piece_num][1] = 502;
						board_coords[1][piece_num][2] = 763;
						pieces[1][piece_num][3] = 2;
					
					}
					else
					{
						pieces[1][piece_num][2] -= 50;
						board_coords[1][piece_num][2] += 50;
					}
					
				
				}
				
				else if (pieces[1][piece_num][3] == 4)
				{
					if (pieces[1][piece_num][1] == 402 && pieces[1][piece_num][2] == 475)
					{
						pieces[1][piece_num][1] += 50;
						pieces[1][piece_num][2] += 50;
						board_coords[1][piece_num][1] = 452;
						board_coords[1][piece_num][2] = 314;
						pieces[1][piece_num][3] = 1;
					
					}
					else if (pieces[1][piece_num][1] == 552 && pieces[1][piece_num][2] == 775)
					{
						pieces[1][piece_num][2] -= 50;
						board_coords[1][piece_num][1] = 554;
						board_coords[1][piece_num][2] = 115;
						pieces[1][piece_num][3] = 3;
					}
					else if (pieces[1][piece_num][1] == 852 && pieces[1][piece_num][2] == 475)
					{
						pieces[1][piece_num][2] -= 50;
						board_coords[1][piece_num][1] = 853;
						board_coords[1][piece_num][2] = 413;
						pieces[1][piece_num][3] = 3;
					
					}
					else
					{
						pieces[1][piece_num][1] += 50;
						board_coords[1][piece_num][1] += 50;
					}
				
				
				
				}
				
			}
		//}
		
	}	
	
	
	//For Green pieces
	if (turn == 2)
	{
	
	
						/*---------------------DIRECTIONS: 1 = upward, 2 = left, 3 = down, 4 = right-------------------------*/
		//if (movement == 1)
		//{
			for (int i = 0; i < turn_val1; i++)
			{
				//Incrementing score for green according to movement
				score2++;
				
			
				if (pieces[2][piece_num][3] == 1)
				{
					if (pieces[2][piece_num][1] == 452 && pieces[2][piece_num][2] == 325)
					{
						pieces[2][piece_num][1] -= 50;
						pieces[2][piece_num][2] += 50;
						board_coords[2][piece_num][1] = 402;
						board_coords[2][piece_num][2] = 465;
						pieces[2][piece_num][3] = 2;
					}
					else if (pieces[2][piece_num][1] == 152 && pieces[2][piece_num][2] == 475)
					{
						pieces[2][piece_num][1] += 50;
						board_coords[2][piece_num][1] = 204;
						board_coords[2][piece_num][2] = 364;
						pieces[2][piece_num][3] = 4;
					}
					else if (pieces[2][piece_num][1] == 452 && pieces[2][piece_num][2] == 775)
					{
						pieces[2][piece_num][1] += 50;
						board_coords[2][piece_num][1] = 503;
						board_coords[2][piece_num][2] = 63;
						pieces[2][piece_num][3] = 4;
					}
					else
					{
						pieces[2][piece_num][2] += 50;
						board_coords[2][piece_num][2] -= 50;
					}
					
				}
				
				else if (pieces[2][piece_num][3] == 2)
				{
					if (pieces[2][piece_num][1] == 152 && pieces[2][piece_num][2] == 375)
					{
						pieces[2][piece_num][2] += 50;
						board_coords[2][piece_num][1] = 154;
						board_coords[2][piece_num][2] = 414;
						pieces[2][piece_num][3] = 1;
					}
					else if (pieces[2][piece_num][1] == 602&& pieces[2][piece_num][2] == 375)
					{
						pieces[2][piece_num][1] -= 50;
						pieces[2][piece_num][2] -= 50;
						board_coords[2][piece_num][1] = 554;
						board_coords[2][piece_num][2] = 514;
						pieces[2][piece_num][3] = 3;
					
					}
					else if (pieces[2][piece_num][1] == 452 && pieces[2][piece_num][2] == 75)
					{
						pieces[2][piece_num][2] += 50;
						board_coords[2][piece_num][1] = 452;
						board_coords[2][piece_num][2] = 716;
						pieces[2][piece_num][3] = 1;
					
					}
					else
					{
						pieces[2][piece_num][1] -= 50;
						board_coords[2][piece_num][1] -= 50;
						Win();
					}
					
				}
				
				else if (pieces[2][piece_num][3] == 3)
				{
					if (pieces[2][piece_num][1] == 552 && pieces[2][piece_num][2] == 525)
					{
						pieces[2][piece_num][1] += 50;
						pieces[2][piece_num][2] -= 50;
						board_coords[2][piece_num][1] = 604;
						board_coords[2][piece_num][2] = 363;
						pieces[2][piece_num][3] = 4;
					
					}
					else if (pieces[2][piece_num][1] == 852 && pieces[2][piece_num][2] == 425)
					{
						if (kill2 == 1)
						{
							pieces[2][piece_num][1] -= 50;
							board_coords[2][piece_num][1] = 805;
							board_coords[2][piece_num][2] = 415;
							pieces[2][piece_num][3] = 2;
							score2 += 15;
						}
						else
						{
							pieces[2][piece_num][2] -= 50;
							board_coords[2][piece_num][2] += 50;
							pieces[2][piece_num][3] = 2;
						}
						
					}
					else if (pieces[2][piece_num][1] == 552 && pieces[2][piece_num][2] == 75)
					{
						pieces[2][piece_num][1] -= 50;
						board_coords[2][piece_num][1] = 502;
						board_coords[2][piece_num][2] = 763;
						pieces[2][piece_num][3] = 2;
					
					}
					else
					{
						pieces[2][piece_num][2] -= 50;
						board_coords[2][piece_num][2] += 50;
					}
					
				
				}
				
				else if (pieces[2][piece_num][3] == 4)
				{
					if (pieces[2][piece_num][1] == 402 && pieces[2][piece_num][2] == 475)
					{
						pieces[2][piece_num][1] += 50;
						pieces[2][piece_num][2] += 50;
						board_coords[2][piece_num][1] = 452;
						board_coords[2][piece_num][2] = 314;
						pieces[2][piece_num][3] = 1;
					
					}
					else if (pieces[2][piece_num][1] == 552 && pieces[2][piece_num][2] == 775)
					{
						pieces[2][piece_num][2] -= 50;
						board_coords[2][piece_num][1] = 554;
						board_coords[2][piece_num][2] = 115;
						pieces[2][piece_num][3] = 3;
					}
					else if (pieces[2][piece_num][1] == 852 && pieces[2][piece_num][2] == 475)
					{
						pieces[2][piece_num][2] -= 50;
						board_coords[2][piece_num][1] = 853;
						board_coords[2][piece_num][2] = 413;
						pieces[2][piece_num][3] = 3;
					
					}
					else
					{
						pieces[2][piece_num][1] += 50;
						board_coords[2][piece_num][1] += 50;
					}
				
				
				
				}
				
			}
		//}
		
	}
	
	
	
	//For Yellow pieces
	if (turn == 3)
	{
							/*---------------------DIRECTIONS: 1 = upward, 2 = left, 3 = down, 4 = right-------------------------*/
		//if (movement == 1)
		//{
			for (int i = 0; i < turn_val1; i++)
			{
				//Incrementing score for yellow according to movement
				score3++;
				
			
				if (pieces[3][piece_num][3] == 1)
				{
					if (pieces[3][piece_num][1] == 452 && pieces[3][piece_num][2] == 325)
					{
						pieces[3][piece_num][1] -= 50;
						pieces[3][piece_num][2] += 50;
						board_coords[3][piece_num][1] = 402;
						board_coords[3][piece_num][2] = 465;
						pieces[3][piece_num][3] = 2;
					}
					else if (pieces[3][piece_num][1] == 152 && pieces[3][piece_num][2] == 475)
					{
						pieces[3][piece_num][1] += 50;
						board_coords[3][piece_num][1] = 204;
						board_coords[3][piece_num][2] = 364;
						pieces[3][piece_num][3] = 4;
					}
					else if (pieces[3][piece_num][1] == 452 && pieces[3][piece_num][2] == 775)
					{
						pieces[3][piece_num][1] += 50;
						board_coords[3][piece_num][1] = 503;
						board_coords[3][piece_num][2] = 63;
						pieces[3][piece_num][3] = 4;
					}
					else
					{
						pieces[3][piece_num][2] += 50;
						board_coords[3][piece_num][2] -= 50;
					}
					
				}
				
				else if (pieces[3][piece_num][3] == 2)
				{
					if (pieces[3][piece_num][1] == 152 && pieces[3][piece_num][2] == 375)
					{
						pieces[3][piece_num][2] += 50;
						board_coords[3][piece_num][1] = 154;
						board_coords[3][piece_num][2] = 414;
						pieces[3][piece_num][3] = 1;
					}
					else if (pieces[3][piece_num][1] == 602 && pieces[3][piece_num][2] == 375)
					{
						pieces[3][piece_num][1] -= 50;
						pieces[3][piece_num][2] -= 50;
						board_coords[3][piece_num][1] = 554;
						board_coords[3][piece_num][2] = 514;
						pieces[3][piece_num][3] = 3;
					
					}
					else if (pieces[3][piece_num][1] == 452 && pieces[3][piece_num][2] == 75)
					{
						pieces[3][piece_num][2] += 50;
						board_coords[3][piece_num][1] = 452;
						board_coords[3][piece_num][2] = 716;
						pieces[3][piece_num][3] = 1;
					
					}
					else
					{
						pieces[3][piece_num][1] -= 50;
						board_coords[3][piece_num][1] -= 50;
					}
					
				}
				
				else if (pieces[3][piece_num][3] == 3)
				{
					if (pieces[3][piece_num][1] == 552 && pieces[3][piece_num][2] == 525)
					{
						pieces[3][piece_num][1] += 50;
						pieces[3][piece_num][2] -= 50;
						board_coords[3][piece_num][1] = 604;
						board_coords[3][piece_num][2] = 363;
						pieces[3][piece_num][3] = 4;
					
					}
					else if (pieces[3][piece_num][1] == 852 && pieces[3][piece_num][2] == 375)
					{
						pieces[3][piece_num][1] -= 50;
						board_coords[3][piece_num][1] = 804;
						board_coords[3][piece_num][2] = 463;
						pieces[3][piece_num][3] = 2;
					
					}
					else if (pieces[3][piece_num][1] == 552 && pieces[3][piece_num][2] == 75)
					{
						pieces[3][piece_num][1] -= 50;
						board_coords[3][piece_num][1] = 502;
						board_coords[3][piece_num][2] = 763;
						pieces[3][piece_num][3] = 2;
					
					}
					else
					{
						pieces[3][piece_num][2] -= 50;
						board_coords[3][piece_num][2] += 50;
						Win();
					}
					
				
				}
				
				else if (pieces[3][piece_num][3] == 4)
				{
					if (pieces[3][piece_num][1] == 402 && pieces[3][piece_num][2] == 475)
					{
						pieces[3][piece_num][1] += 50;
						pieces[3][piece_num][2] += 50;
						board_coords[3][piece_num][1] = 452;
						board_coords[3][piece_num][2] = 314;
						pieces[3][piece_num][3] = 1;
					
					}
					else if (pieces[3][piece_num][1] == 502 && pieces[3][piece_num][2] == 775)
					{
						if (kill3 == 1)
						{
							pieces[3][piece_num][2] -= 50;
							board_coords[3][piece_num][1] = 502;
							board_coords[3][piece_num][2] = 113;
							pieces[3][piece_num][3] = 3;
							score3 += 15;
						}
						else
						{
							pieces[3][piece_num][1] += 50;
							board_coords[3][piece_num][1] += 50;
							pieces[3][piece_num][3] = 3;
						}


					}
					
					else if (pieces[3][piece_num][1] == 852 && pieces[3][piece_num][2] == 475)
					{
						pieces[3][piece_num][2] -= 50;
						board_coords[3][piece_num][1] = 853;
						board_coords[3][piece_num][2] = 413;
						pieces[3][piece_num][3] = 3;
					
					}
					else
					{
						pieces[3][piece_num][1] += 50;
						board_coords[3][piece_num][1] += 50;
					}
				
				
				
				}
				
			}
		//}
		
	}
	
	
	
	//For Blue pieces
	if (turn == 4)
	{
	
						/*---------------------DIRECTIONS: 1 = upward, 2 = left, 3 = down, 4 = right-------------------------*/
		//if (movement == 1)
		//{
			for (int i = 0; i < turn_val1; i++)
			{
				//Incrementing score for blue according to movement
				score4++;
				
			
				if (pieces[4][piece_num][3] == 1)
				{
					if (pieces[4][piece_num][1] == 452 && pieces[4][piece_num][2] == 325)
					{
						pieces[4][piece_num][1] -= 50;
						pieces[4][piece_num][2] += 50;
						board_coords[4][piece_num][1] = 402;
						board_coords[4][piece_num][2] = 465;
						pieces[4][piece_num][3] = 2;
					}
					else if (pieces[4][piece_num][1] == 152 && pieces[4][piece_num][2] == 425)
					{
						if (kill4 == 1)
						{
							pieces[4][piece_num][1] += 50;
							board_coords[4][piece_num][1] = 204;
							board_coords[4][piece_num][2] = 416;
							pieces[4][piece_num][3] = 4;
							score4 += 15;
						}
						else
						{
							pieces[4][piece_num][2] += 50;
							board_coords[4][piece_num][2] -= 50;
							pieces[4][piece_num][3] = 4;
						}
						

					}
					else if (pieces[4][piece_num][1] == 452 && pieces[4][piece_num][2] == 775)
					{
						pieces[4][piece_num][1] += 50;
						board_coords[4][piece_num][1] = 503;
						board_coords[4][piece_num][2] = 63;
						pieces[4][piece_num][3] = 4;
					}
					else
					{
						pieces[4][piece_num][2] += 50;
						board_coords[4][piece_num][2] -= 50;
					}
					
				}
				
				else if (pieces[4][piece_num][3] == 2)
				{
					if (pieces[4][piece_num][1] == 152 && pieces[4][piece_num][2] == 375)
					{
						pieces[4][piece_num][2] += 50;
						board_coords[4][piece_num][1] = 154;
						board_coords[4][piece_num][2] = 414;
						pieces[4][piece_num][3] = 1;
					}
					else if (pieces[4][piece_num][1] == 602 && pieces[4][piece_num][2] == 375)
					{
						pieces[4][piece_num][1] -= 50;
						pieces[4][piece_num][2] -= 50;
						board_coords[4][piece_num][1] = 554;
						board_coords[4][piece_num][2] = 514;
						pieces[4][piece_num][3] = 3;
					
					}
					else if (pieces[4][piece_num][1] == 452 && pieces[4][piece_num][2] == 75)
					{
						pieces[4][piece_num][2] += 50;
						board_coords[4][piece_num][1] = 452;
						board_coords[4][piece_num][2] = 716;
						pieces[4][piece_num][3] = 1;
					
					}
					else
					{
						pieces[4][piece_num][1] -= 50;
						board_coords[4][piece_num][1] -= 50;
					}
					
				}
				
				else if (pieces[4][piece_num][3] == 3)
				{
					if (pieces[4][piece_num][1] == 552 && pieces[4][piece_num][2] == 525)
					{
						pieces[4][piece_num][1] += 50;
						pieces[4][piece_num][2] -= 50;
						board_coords[4][piece_num][1] = 604;
						board_coords[4][piece_num][2] = 363;
						pieces[4][piece_num][3] = 4;
					
					}
					else if (pieces[4][piece_num][1] == 852 && pieces[4][piece_num][2] == 375)
					{
						pieces[4][piece_num][1] -= 50;
						board_coords[4][piece_num][1] = 804;
						board_coords[4][piece_num][2] = 463;
						pieces[4][piece_num][3] = 2;
					
					}
					else if (pieces[4][piece_num][1] == 552 && pieces[4][piece_num][2] == 75)
					{
						pieces[4][piece_num][1] -= 50;
						board_coords[4][piece_num][1] = 502;
						board_coords[4][piece_num][2] = 763;
						pieces[4][piece_num][3] = 2;
					
					}
					else
					{
						pieces[4][piece_num][2] -= 50;
						board_coords[4][piece_num][2] += 50;
					}
					
				
				}
				
				else if (pieces[4][piece_num][3] == 4)
				{
					if (pieces[4][piece_num][1] == 402 && pieces[4][piece_num][2] == 475)
					{
						pieces[4][piece_num][1] += 50;
						pieces[4][piece_num][2] += 50;
						board_coords[4][piece_num][1] = 452;
						board_coords[4][piece_num][2] = 314;
						pieces[4][piece_num][3] = 1;
					
					}
					
					else if (pieces[4][piece_num][1] == 552 && pieces[4][piece_num][2] == 775)
					{
						pieces[4][piece_num][2] -= 50;
						board_coords[4][piece_num][1] = 554;
						board_coords[4][piece_num][2] = 115;
						pieces[4][piece_num][3] = 3;
					}
					
					else if (pieces[4][piece_num][1] == 852 && pieces[4][piece_num][2] == 475)
					{
						pieces[4][piece_num][2] -= 50;
						board_coords[4][piece_num][1] = 853;
						board_coords[4][piece_num][2] = 413;
						pieces[4][piece_num][3] = 3;
					
					}
					else
					{
						pieces[4][piece_num][1] += 50;
						board_coords[4][piece_num][1] += 50;
						Win();
					}
				
				
				
				}
				
			}
			
			
		//}
		
	}

	
	//Execution of Stack and killing functions to check them after every turn(movement)
	Stack();
	Kill();
	
	
	//Changing of turns
	if (turn_val1 != 6 || six > 2)
	{
		ChangeTurns();
	}
	else
	{
		turn_val1 = 0;
	}
	
	
	movement = 0;

}



//To display the final scoreboard after game is over according to number of players
void ScoreBoard()
{
	DrawSquare(0, 0, 2000, colors[LIGHT_BLUE]);
	DrawString(400, 700, "ScoreBoard", colors[BLACK]);
	DrawString(390, 800, "GAME OVER", colors[BLACK]);
	DrawString(360, 600, name1, colors[BROWN]);
	
	if (players >= 2)
	{
		switch (color1)
		{
			case 1:
				DrawString(530, 600, to_string(score1), colors[BROWN]);
				break;
			case 2:
				DrawString(530, 600, to_string(score2), colors[BROWN]);
				break;
			case 3:
				DrawString(530, 600, to_string(score3), colors[BROWN]);
				break;
			case 4:
				DrawString(530, 600, to_string(score4), colors[BROWN]);
				break;
		}
		
		DrawString(360, 500, name2, colors[BROWN]);
		
		switch (color2)
		{
			case 1:
				DrawString(530, 500, to_string(score1), colors[BROWN]);
				break;
			case 2:
				DrawString(530, 500, to_string(score2), colors[BROWN]);
				break;
			case 3:
				DrawString(530, 500, to_string(score3), colors[BROWN]);
				break;
			case 4:
				DrawString(530, 500, to_string(score4), colors[BROWN]);
				break;
		}
	}
	if (players >= 3)
	{
	
		DrawString(360, 400, name3, colors[BROWN]);
		
		switch (color3)
		{
			case 1:
				DrawString(530, 400, to_string(score1), colors[BROWN]);
				break;
			case 2:
				DrawString(530, 400, to_string(score2), colors[BROWN]);
				break;
			case 3:
				DrawString(530, 400, to_string(score3), colors[BROWN]);
				break;
			case 4:
				DrawString(530, 400, to_string(score4), colors[BROWN]);
				break;	
		}
	}
	
	if (players >= 4)
	{
		
		DrawString(360, 300, name4, colors[BROWN]);
		
		switch (color4)
		{
			case 1:
				 DrawString(530, 300, to_string(score1), colors[BROWN]);
				 break;
			case 2:
				DrawString(530, 300, to_string(score2), colors[BROWN]);
				break;
			case 3:
				DrawString(530, 300, to_string(score3), colors[BROWN]);
				break;
			case 4:
				DrawString(530, 300, to_string(score4), colors[BROWN]);
				break;
		}
	}
	
	DrawRectangle(360, 100, 200, 100, colors[MAROON]);
	DrawString(390, 140, "Leaderboards", colors[WHITE]);
	

}






/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.4/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	StartMenu();
	
		//For two players
		if (players == 2)
		{
			//Text boxes for names
			DrawString(130, 420, "Player#1 Name: ", colors[RED]);
			DrawRectangle(310, 400, 500, 60, colors[WHITE]);
			DrawString(130, 320, "Player#2 Name: ", colors[SKY_BLUE]);
			DrawRectangle(310, 300, 500, 60, colors[WHITE]);
			
			
			//Outputting first name
			DrawString(340, 420, name1, colors[BLACK]);
			
			//Outputting second name		
			DrawString(340, 320, name2, colors[BLACK]);
			
			//Disclaimer
			DrawString(130, 40, "*To Proceed, Enter name of Second Player", colors[WHITE]);
			
			//For button to appear
			if (done == 2)
			{
				//Proceed button
				DrawRectangle(860, 50, 100, 40, colors[BLACK]); 
				DrawString(870, 60, "Proceed", colors[WHITE]); 
			}


			//To proceed to next menu
			if (proceed == 1)
			{	
				//Background
				DrawRectangle(0, 0, 1020, 840, colors[NAVY]);
				
				//For selection of colours
				DrawString(460, 770,  "COLORS" , colors[BLACK]);
				DrawRectangle(260, 650, 150, 80, colors[BLACK]);
				DrawRectangle(600, 650, 150, 80, colors[WHITE]);
				DrawString(295, 680, "Random", colors[WHITE]);
				DrawString(605, 680, "Select Colours", colors[BLACK]);
				DrawString(485, 580, "*TWO PLAYERS CAN'T HAVE SAME COLOR", colors[WHITE]); 

				
				//For Selection of colours
				if (col_check == 2)
				{
				
					DrawString(485, 620, "*CHOOSE COLOR OF SECOND TO PROCEED", colors[WHITE]);
					//First player1 colour
					DrawString(80, 580, "Colour for Player 1: ", colors[RED]);
					
					DrawCircle(180, 500, 50, colors[RED]);
					DrawCircle(380, 500, 50, colors[GREEN]);
					DrawCircle(580, 500, 50, colors[OLIVE]);
					DrawCircle(780, 500, 50, colors[BLUE]);
					
					//First color selected
					if (complete == 1 || complete == 2)
					{
						//For player2 color
						DrawString(80, 400, "Color for Player 2: ", colors[GREEN]);
						//Displaying available colors
						DrawCircle(180, 340, 50, colors[RED]);
						DrawCircle(380, 340, 50, colors[GREEN]);
						DrawCircle(580, 340, 50, colors[OLIVE]);
						DrawCircle(780, 340, 50, colors[BLUE]);

					}

					//To start game					
					if (complete == 2)
					{
						//Proceed button
						DrawRectangle(790, 30, 100, 40, colors[BLACK]); 
						DrawString(800, 40, "Proceed", colors[WHITE]);
					}
				
				}
				
				//For random colours
				else if (col_check == 1)
				{
					//Assigning random colours to every player
					InitRandomizer();
					color1 = GetRandInRange(1, 5);
					color2 = GetRandInRange(1, 5);
				
					//Making sure all colours are unique
					while (color2 == color1)
					{
						color2 = GetRandInRange(1, 5);
					}
					
					//Proceed button
					DrawRectangle(790, 30, 100, 40, colors[BLACK]); 
					DrawString(800, 40, "Proceed", colors[WHITE]);
				
				}
				
			
			}
		}

			
			
			
		//For three players	
		if (players == 3)
		{
			//Text boxes for names
			DrawString(130, 420, "Player#1 Name: ", colors[RED]);
			DrawRectangle(310, 400, 500, 60, colors[WHITE]);
			DrawString(130, 320, "Player#2 Name: ", colors[SKY_BLUE]);
			DrawRectangle(310, 300, 500, 60, colors[WHITE]);
			DrawString(130, 220, "Player#3 Name: ", colors[LIGHT_GREEN]);
			DrawRectangle(310, 200, 500, 60, colors[WHITE]);
			
			//Outputting first name
			DrawString(340, 420, name1, colors[BLACK]);
			
			//Outputting second name
			DrawString(340, 320, name2, colors[BLACK]);
			
			//Outputting third name
			DrawString(340, 220, name3, colors[BLACK]);
			
			//Disclaimer
			DrawString(130, 40, "*To Proceed, Enter name of Third Player", colors[WHITE]);
			
			//For button to appear
			if (done == 3)
			{
				//Proceed button
				DrawRectangle(860, 50, 100, 40, colors[BLACK]); 
				DrawString(870, 60, "Proceed", colors[WHITE]); 
			}
			
			//To proceed to next menu
			if (proceed == 1)
			{
				//Background
				DrawRectangle(0, 0, 1020, 840, colors[NAVY]);
				
				//For selection of colours
				DrawString(460, 770,  "COLORS" , colors[BLACK]);
				DrawRectangle(260, 650, 150, 80, colors[BLACK]);
				DrawRectangle(600, 650, 150, 80, colors[WHITE]);
				DrawString(295, 680, "Random", colors[WHITE]);
				DrawString(605, 680, "Select Colours", colors[BLACK]);
				DrawString(485, 580, "*TWO PLAYERS CAN'T HAVE SAME COLOR", colors[WHITE]);


			/*COLORS: 1 = RED; 2 = GREEN; 3 = YELLOW; 4 = BLUE*/
			
				//For Selection
				if (col_check == 2)
				{
					DrawString(485, 620, "*CHOOSE COLOR OF THIRD TO PROCEED", colors[WHITE]);
				
					//First player1 colour
					DrawString(80, 580, "Colour for Player 1: ", colors[RED]);
					
					DrawCircle(180, 500, 50, colors[RED]);
					DrawCircle(380, 500, 50, colors[GREEN]);
					DrawCircle(580, 500, 50, colors[OLIVE]);
					DrawCircle(780, 500, 50, colors[BLUE]);
					
					//First color selected
					if (complete == 1 || complete == 2 || complete == 3)
					{
						//For player2 color
						DrawString(80, 400, "Color for Player 2: ", colors[GREEN]);
						//Displaying available colors
						DrawCircle(180, 340, 50, colors[RED]);
						DrawCircle(380, 340, 50, colors[GREEN]);
						DrawCircle(580, 340, 50, colors[OLIVE]);
						DrawCircle(780, 340, 50, colors[BLUE]);

					}
					
					//Second color selected
					if (complete == 2 || complete == 3)
					{
						//For player3 color
						DrawString(80, 220, "Color for Player 3: ", colors[OLIVE]);
						//Displaying available colors
						DrawCircle(180, 160, 50, colors[RED]);
						DrawCircle(380, 160, 50, colors[GREEN]);
						DrawCircle(580, 160, 50, colors[OLIVE]);
						DrawCircle(780, 160, 50, colors[BLUE]);

					}
					
					//To start game
					if (complete == 3)
					{
						//Proceed button
						DrawRectangle(790, 30, 100, 40, colors[BLACK]); 
						DrawString(800, 40, "Proceed", colors[WHITE]);
					}
				
				}
				
				//For random colours
				else if (col_check == 1)
				{
					//Assigning random colours to every player
					InitRandomizer();
					color1 = GetRandInRange(1, 5);
					color2 = GetRandInRange(1, 5);
					color3 = GetRandInRange(1, 5);
				
					//Making sure all colours are unique
					while ((color2 == color1) || (color2 == color3))
					{
						color2 = GetRandInRange(1, 5);
					}
					
					//Making sure all colours are unique
					while ((color3 == color1) || (color3 == color2))
					{
						color3 = GetRandInRange(1, 5);
					}
					
					//Proceed button
					DrawRectangle(790, 30, 100, 40, colors[BLACK]); 
					DrawString(800, 40, "Proceed", colors[WHITE]);
				
				}
					
			
			}
			
		}
		
		//For 4 players
		if (players == 4)
		{
			//Text boxes for names
			DrawString(130, 420, "Player#1 Name: ", colors[RED]);
			DrawRectangle(310, 400, 500, 60, colors[WHITE]);
			DrawString(130, 320, "Player#2 Name: ", colors[SKY_BLUE]);
			DrawRectangle(310, 300, 500, 60, colors[WHITE]);
			DrawString(130, 220, "Player#3 Name: ", colors[LIGHT_GREEN]);
			DrawRectangle(310, 200, 500, 60, colors[WHITE]);
			DrawString(130, 120, "Player#4 Name: ", colors[OLIVE]);
			DrawRectangle(310, 100, 500, 60, colors[WHITE]);

			//Outputting first name
			DrawString(340, 420, name1, colors[BLACK]);
			
			//Outputting second name
			DrawString(340, 320, name2, colors[BLACK]);	
			
			//Outputting third name
			DrawString(340, 220, name3, colors[BLACK]);
			
			//Outputting fourth name
			DrawString(340, 120, name4, colors[BLACK]);
			
			//Disclaimer
			DrawString(130, 40, "*To Proceed, Enter name of Fourth Player", colors[WHITE]);
			
			//For button to appear
			if (done == 4)
			{
				//Proceed button
				DrawRectangle(860, 50, 100, 40, colors[BLACK]); 
				DrawString(870, 60, "Proceed", colors[WHITE]); 
			}
			
			//To proceed to next menu
			if (proceed == 1)
			{
				//Background
				DrawRectangle(0, 0, 1020, 840, colors[NAVY]);
				
				//For selection of colours
				DrawString(460, 770,  "COLORS" , colors[BLACK]);
				DrawRectangle(260, 650, 150, 80, colors[BLACK]);
				DrawRectangle(600, 650, 150, 80, colors[WHITE]);
				DrawString(295, 680, "Random", colors[WHITE]);
				DrawString(605, 680, "Select Colours", colors[BLACK]);
				DrawString(485, 580, "*TWO PLAYERS CAN'T HAVE SAME COLOR", colors[WHITE]);

				
			/*COLORS: 1 = RED; 2 = GREEN; 3 = YELLOW; 4 = BLUE*/
			
				//For Selection
				if (col_check == 2)
				{
					DrawString(485, 620, "*CHOOSE COLOR OF THIRD TO PROCEED", colors[WHITE]);
				
					//First player1 colour
					DrawString(80, 580, "Colour for Player 1: ", colors[RED]);
					
					DrawCircle(180, 500, 50, colors[RED]);
					DrawCircle(380, 500, 50, colors[GREEN]);
					DrawCircle(580, 500, 50, colors[OLIVE]);
					DrawCircle(780, 500, 50, colors[BLUE]);
					
					//First color selected
					if (complete == 1 || complete == 2 || complete == 3)
					{
						//For player2 color
						DrawString(80, 400, "Color for Player 2: ", colors[GREEN]);
						//Displaying available colors
						DrawCircle(180, 340, 50, colors[RED]);
						DrawCircle(380, 340, 50, colors[GREEN]);
						DrawCircle(580, 340, 50, colors[OLIVE]);
						DrawCircle(780, 340, 50, colors[BLUE]);

					}
					
					//Second color selected
					if (complete == 2 || complete == 3)
					{
						//For player3 color
						DrawString(80, 220, "Color for Player 3: ", colors[OLIVE]);
						//Displaying available colors
						DrawCircle(180, 160, 50, colors[RED]);
						DrawCircle(380, 160, 50, colors[GREEN]);
						DrawCircle(580, 160, 50, colors[OLIVE]);
						DrawCircle(780, 160, 50, colors[BLUE]);

					}
					
					//Third color selected
					if (complete == 3)
					{
						//For player4 color
						DrawString(70, 50, "Color for Player 4 is ", colors[LIGHT_BLUE]);
						
						switch (color4)
						{
							case 1:
								DrawString(275, 50, "RED ", colors[RED]);
								break;
							case 2:
								DrawString(275, 50, "GREEN ", colors[GREEN]);
								break;
							case 3:
								DrawString(275, 50, "YELLOW ", colors[OLIVE]);
								break;
							case 4:
								DrawString(275, 50, "BLUE ", colors[AQUA]);
								break;
						
						}
						
						//Proceed button
						DrawRectangle(790, 30, 100, 40, colors[BLACK]); 
						DrawString(800, 40, "Proceed", colors[WHITE]);
						
						
					
					}
				
				}
				
				//For random colours
				else if (col_check == 1)
				{
					//Assigning random colours to every player
					InitRandomizer();
					color1 = GetRandInRange(1, 5);
					color2 = GetRandInRange(1, 5);
					color3 = GetRandInRange(1, 5);
					color4 = GetRandInRange(1, 5);
				
					//Making sure all colours are unique
					while ((color2 == color1) || (color2 == color3) || (color2 == color4))
					{
						color2 = GetRandInRange(1, 5);
					}
					
					//Making sure all colours are unique
					while ((color3 == color1) || (color3 == color2) || (color3 == color4))
					{
						color3 = GetRandInRange(1, 5);
					}
					
					//Making sure all colours are unique
					while ((color4 == color1) || (color4 == color2) || (color4 == color3))
					{
						color4 = GetRandInRange(1, 5);
					}
					
					//Proceed button
					DrawRectangle(790, 30, 100, 40, colors[BLACK]); 
					DrawString(800, 40, "Proceed", colors[WHITE]);
				
				}
			
			}		
			
		}
		
		
	/*--------------------THE GAME----------------------*/
	
		if (game == 1)
		{
			Board();   /*Initialization of board*/
			
			Dice(dice_num);      /*Dice according to turn*/
			
			
		/*COLORS: 1 = RED; 2 = GREEN; 3 = YELLOW; 4 = BLUE*/
		
		/*-----------Displaying names of user on board--------------*/
			if (players >= 2)
			{
				switch (color1)
				{
					case 1:
						DrawString(100, 20, name1, colors[WHITE]);
						DrawString(0, 100, "Score: ", colors[WHITE]);
						DrawString(70, 100, to_string(score1), colors[WHITE]);
						break;
					case 2:
						DrawString(800, 20, name1, colors[WHITE]);
						DrawString(880, 100, "Score: ", colors[WHITE]);
						DrawString(950, 100, to_string(score2), colors[WHITE]);
						break;
					case 3:
						DrawString(800, 810, name1, colors[WHITE]);
						DrawString(880, 730, "Score: ", colors[WHITE]);
						DrawString(950, 730, to_string(score3), colors[WHITE]);
						break;
					case 4:
						DrawString(100, 810, name1, colors[WHITE]);
						DrawString(0, 730, "Score: ", colors[WHITE]);
						DrawString(70, 730, to_string(score4), colors[WHITE]);
						break;
				
				}
				
				switch (color2)
				{
					case 1:
						DrawString(100, 20, name2, colors[WHITE]);
						DrawString(0, 100, "Score: ", colors[WHITE]);
						DrawString(70, 100, to_string(score1), colors[WHITE]);
						break;
					case 2:
						DrawString(800, 20, name2, colors[WHITE]);
						DrawString(880, 100, "Score: ", colors[WHITE]);
						DrawString(950, 100, to_string(score2), colors[WHITE]);
						break;
					case 3:
						DrawString(800, 810, name2, colors[WHITE]);
						DrawString(880, 730, "Score: ", colors[WHITE]);
						DrawString(950, 730, to_string(score3), colors[WHITE]);
						break;
					case 4:
						DrawString(100, 810, name2, colors[WHITE]);
						DrawString(0, 730, "Score: ", colors[WHITE]);
						DrawString(70, 730, to_string(score4), colors[WHITE]);
						break;
				
				}
			}
			
			if (players >= 3)
			{
				switch (color3)
				{
					case 1:
						DrawString(100, 20, name3, colors[WHITE]);
						DrawString(0, 100, "Score: ", colors[WHITE]);
						DrawString(70, 100, to_string(score1), colors[WHITE]);
						break;
					case 2:
						DrawString(800, 20, name3, colors[WHITE]);
						DrawString(880, 100, "Score: ", colors[WHITE]);
						DrawString(950, 100, to_string(score2), colors[WHITE]);
						break;
					case 3:
						DrawString(800, 810, name3, colors[WHITE]);
						DrawString(880, 730, "Score: ", colors[WHITE]);
						DrawString(950, 730, to_string(score3), colors[WHITE]);
						break;
					case 4:
						DrawString(100, 810, name3, colors[WHITE]);
						DrawString(0, 730, "Score: ", colors[WHITE]);
						DrawString(70, 730, to_string(score4), colors[WHITE]);
						break;
				
				}
			}
			
			if (players >= 4)
			{
				switch (color4)
				{
					case 1:
						DrawString(100, 20, name4, colors[WHITE]);
						DrawString(0, 100, "Score: ", colors[WHITE]);
						DrawString(70, 100, to_string(score1), colors[WHITE]);
						break;
					case 2:
						DrawString(800, 20, name4, colors[WHITE]);
						DrawString(880, 100, "Score: ", colors[WHITE]);
						DrawString(950, 100, to_string(score2), colors[WHITE]);
						break;
					case 3:
						DrawString(800, 810, name4, colors[WHITE]);
						DrawString(880, 730, "Score: ", colors[WHITE]);
						DrawString(950, 730, to_string(score3), colors[WHITE]);
						break;
					case 4:
						DrawString(100, 810, name4, colors[WHITE]);
						DrawString(0, 730, "Score: ", colors[WHITE]);
						DrawString(70, 730, to_string(score4), colors[WHITE]);
						break;
				
				}
			}
			
			
		/*------------------Displaying scores of user on board---------------*/
		
		
		
		
		
		
		
		
		
	/*--------------For getting to know who gets first turn-------------------*/
		
			//Array for colors of users
			color[0] = color1;
			color[1] = color2;
			color[2] = color3;
			color[3] = color4;
			
			if (temp_turn > 0)
			{		
				clear = 0;	
				
				//Checking if color is occupied
				for (int i = 0; i < 4; i++)
				{
					if (color[i] == temp_turn)
					{
						clear = 1;
						break;
					}
				}
			
				//Prompting for turn
				if (clear == 1)
				{
					switch (temp_turn)
					{
						case 4:
							disc_pos[0] = 0;
							disc_pos[1] = 760;
							pos4[0] = 0;
							pos4[1] = 760;
							
							DrawRectangle(disc_pos[0], disc_pos[1], 130, 40, colors[WHITE]);
							DrawString(disc_pos[0], disc_pos[1] + 10, "Roll the dice", colors[BLACK]);
							break;
						case 3:
							disc_pos[0] = 885;
							disc_pos[1] = 760;
							pos3[0] = 885;
							pos3[1] = 760;
							
							DrawRectangle(disc_pos[0], disc_pos[1], 130, 40, colors[WHITE]);
							DrawString(disc_pos[0], disc_pos[1] + 10, "Roll the dice", colors[BLACK]);	
							break;
						case 2:
							disc_pos[0] = 885;
							disc_pos[1] = 50;
							pos2[0] = 885;
							pos2[1] = 50;
							
							DrawRectangle(disc_pos[0], disc_pos[1], 130, 40, colors[WHITE]);
							DrawString(disc_pos[0], disc_pos[1] + 10, "Roll the dice", colors[BLACK]);
							break;
						case 1:
							disc_pos[0] = 0;
							disc_pos[1] = 50;
							pos1[0] = 0;
							pos1[1] = 50;
							
							DrawRectangle(disc_pos[0], disc_pos[1], 130, 40, colors[WHITE]);
							DrawString(disc_pos[0], disc_pos[1] + 10, "Roll the dice", colors[BLACK]);	
							break;
					
					}
				}
				else
				{
					temp_turn--;
					DrawRectangle(380, 800, 280, 50, colors[WHITE]);
					DrawString(400, 810, "Move Mouse to continue", colors[BLACK]);
				}
			}
			
			//to start turns of game
			if (temp_turn == 0)
			{
				turn_start = 1;
				temp_turn = -1;
			}
			
			
			//Comparisons to determine first and max turn
			if (turn_start == 1)
			{
				if (turn1 >= turn2 && turn1 >= turn3 && turn1 >= turn4)
				{
					turn = 1;
					
				}
				else if (turn2 > turn1 && turn2 >= turn3 && turn2 >= turn4)
				{
					turn = 2;
				}
				else if (turn3 > turn1 && turn3 > turn2 && turn3 >= turn4)
				{
					turn = 3;
				}
				else if (turn4 > turn1 && turn4 > turn2 && turn4 > turn3)
				{
					turn = 4;
				}
				turn_start = 0;
			}
			
			
	/*--------------For getting to know who gets first turn-------------------*/
	
	/*---------------------START OF TURNS AND MOVING--------------------*/
	
			if (turn > 0 && temp_turn <= 0)
			{
			
				ShowTurn();	
				
				if (turn_val1 > 0)
				{
					DrawRectangle(380, 800, 270, 50, colors[WHITE]);
					DrawString(400, 810, "Select a piece to Move", colors[BLACK]);
				}
				
			}
			
			if (players_left == 1)
			{
				game = 2;
				
			}
			
			
			
		}	
		
		if (game == 2)
		{
			ScoreBoard();
		}		
	
		
		
		

	glutSwapBuffers(); // do not modify this line..
	
	

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/


	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;
		}
		
	
	//For entering name
	if ((key >= 48 && key <= 57) || (key >= 65 && key <=90) || (key >= 97 && key <= 122) || (key == 8) || (key == ' '))
	{
		//For first name
		if (check == 1)
		{
			done = 1;
			
			//Normal characters
			if (key != 8)
			{
				name1 += key;
			
			}
			//Backspace
			else if (name1.length() != 0)
			{
				name1.resize(name1.length() - 1);
				
			}
			
			
		}
		
		//For second name
		else if (check == 2)
		{
			done = 2;
			
			//Normal characters
			if (key != 8)
			{
				name2 += key;
			
			}
			//Backspace
			else if (name2.length() != 0)
			{
				name2.resize(name2.length() - 1);
				
			}
		
		}
		
		//For third name
		else if (check == 3)
		{
			done = 3;
			
			//Normal characters
			if (key != 8)
			{
				name3 += key;
			
			}
			//Backspace
			else if (name3.length() != 0)
			{
				name3.resize(name3.length() - 1);
				
			}
		
		}
		
		//For fourth name
		else if (check == 4)
		{
			done = 4;
			
			//Normal characters
			if (key != 8)
			{
				name4 += key;
			
			}
			//Backspace
			else if (name4.length() != 0)
			{
				name4.resize(name4.length() - 1);
				
			}
		
		}
		
		//For functionality of space bar for dice roll
		if (game == 1)
		{
		
			if (key == ' ')
			{
				InitRandomizer();
				dice_num = GetRandInRange(1, 7);
				

				
				//For initial turn to determine order
				if (temp_turn == 1)
				{
					turn1 = dice_num;
						
					//Changing turn according to colors
					if (clear == 1)
					{
						temp_turn--;
							
					}
						
				}
				else if (temp_turn == 2)
				{
					turn2 = dice_num;
						
					//Changing turn according to colors
					if (clear == 1)
					{
						temp_turn--;
						
					}
						
				}
				else if (temp_turn == 3)
				{
					turn3 = dice_num;
						
					//Changing turn according to colors
					if (clear == 1)
					{
						temp_turn--;
							
					}

				}
				else if (temp_turn == 4)
				{
					turn4 = dice_num;
						
					//Changing turn according to colors
					if (clear == 1)
					{
						temp_turn--;
					}
				}
				
				//For turns after start of game
				if (temp_turn < 0)
				{
					turn_val1 = dice_num;
					next_turn = 1;
					
					if (turn_val1 == 6)
					{
						six++;
					}
					
					if (six > 2)
					{
						ChangeTurns();
					}
				
				}
				
				
			}
			
		
		}
		
	}
	
	
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {




	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{

	
		if (proceed == 0)
		{
	
			//Selecting number of players
			if ((x >= 89 && x <= 211) && (y >= 180  && y <= 300))
			{
				players = 2;
				players_left = 2;
			}
			else if ((x >= 390 && x <= 511) && (y >= 180  && y <= 300))
			{
				players = 3;
				players_left = 3;
			}
			else if ((x >= 691 && x <= 811) && (y >= 180  && y <= 300))
			{
				players = 4;
				players_left = 4;
			}
			
			//Initializing check variable
			check = 0;
			
			//Selecting text box for name
			if ((x >= 310 && x <= 810) && (y >= 379  && y <= 440))
			{
				check = 1;
				
				
			}
			else if ((x >= 310 && x <= 810) && (y >= 482  && y <= 540))
			{
				check = 2;
				
			}
			else if ((x >= 310 && x <= 810) && (y >= 582  && y <= 640))
			{
				check = 3;
				
			}
			else if ((x >= 310 && x <= 810) && (y >= 682  && y <= 740))
			{
				check = 4;
				
			}
		
		}
		
		//Pressing the proceed button
		if ((x >= 861 && x <= 962) && (y >= 753  && y <= 790))
		{
			proceed = 1;
		
		}
			
		
		
		
		if (game == 0)
		{
		
			//For colours options
			if ((x >= 262 && x <= 411) && (y >= 114  && y <= 192))
			{
				col_check = 1;
			}
			if ((x >= 600 && x <= 749) && (y >= 114  && y <= 192))
			{
				col_check = 2;
			}
		

			//For selection of colors for first
			if ((x >= 131 && x <= 231) && (y >= 290  && y <= 390))
			{
				color1 = 1;
				complete = 1;
			}
			else if ((x >= 331 && x <= 431) && (y >= 290  && y <= 390))
			{
				color1 = 2;
				complete = 1;
			}
			else if ((x >= 531 && x <= 631) && (y >= 290  && y <= 390))
			{
				color1 = 3;
				complete = 1;
			}
			else if ((x >= 731 && x <= 831) && (y >= 290  && y <= 390))
			{
				color1 = 4;
				complete = 1;
			}
			

			//For selection of available colors of second
			if (color1 == 1)
			{
				if ((x >= 331 && x <= 431) && (y >= 450  && y <= 550))
				{
					color2 = 2;
					complete = 2;
				}
				else if ((x >= 531 && x <= 631) && (y >= 450  && y <= 550))
				{
					color2 = 3;
					complete = 2;
				}
				else if ((x >= 731 && x <= 831) && (y >= 450  && y <= 550))
				{
					color2 = 4;
					complete = 2;
				}
			}
			else if (color1 == 2)
			{
				if ((x >= 131 && x <= 231) && (y >= 450  && y <= 550))
				{
					color2 = 1;
					complete = 2;
				}
				else if ((x >= 531 && x <= 631) && (y >= 450  && y <= 550))
				{
					color2 = 3;
					complete = 2;
				}
				else if ((x >= 731 && x <= 831) && (y >= 450  && y <= 550))
				{
					color2 = 4;
					complete = 2;
				}
			
			
			}
			else if (color1 == 3)
			{
				if ((x >= 131 && x <= 231) && (y >= 450  && y <= 550))
				{
					color2 = 1;
					complete = 2;
				}
				else if ((x >= 331 && x <= 431) && (y >= 450  && y <= 550))
				{
					color2 = 2;
					complete = 2;
				}
				else if ((x >= 731 && x <= 831) && (y >= 450  && y <= 550))
				{
					color2 = 4;
					complete = 2;
				}
			
			}
			else if (color1 == 4)
			{
				if ((x >= 131 && x <= 231) && (y >= 450  && y <= 550))
				{
					color2 = 1;
					complete = 2;
				}
				else if ((x >= 331 && x <= 431) && (y >= 450  && y <= 550))
				{
					color2 = 2;
					complete = 2;
				}
				else if ((x >= 531 && x <= 631) && (y >= 450  && y <= 550))
				{
					color2 = 3;
					complete = 2;
				}
				
				
			}
			
			/*COLORS: 1 = RED; 2 = GREEN; 3 = YELLOW; 4 = BLUE*/
			
			
			//For selection of available colors for third player and if possible, fourth player
			if ((color1 == 1 && color2 == 4) || (color1 == 4 && color2 == 1))
			{
				if ((x >= 331 && x <= 431) && (y >= 631  && y <= 731)) //Green
				{
					color3 = 2;
					complete = 3;
					if (players == 4)
					{
						color4 = 3;
					}
				}
				else if ((x >= 531 && x <= 631) && (y >= 631  && y <= 731)) // Yellow
				{
					color3 = 3;
					complete = 3;
					if (players == 4)
					{
						color4 = 2;
					}
				}
			}
			
			else if ((color1 == 1 && color2 == 3) || (color1 == 3 && color2 == 1))
			{
				if ((x >= 331 && x <= 431) && (y >= 631  && y <= 731)) //Green
				{
					color3 = 2;
					complete = 3;
					if (players == 4)
					{
						color4 = 4;
					}
				}
				else if ((x >= 731 && x <= 831) && (y >= 631  && y <= 731)) //Blue
				{
					color3 = 4;
					complete = 3;
					if (players == 4)
					{
						color4 = 2;
					}
				}
			
			}
			
			else if ((color1 == 1 && color2 == 2) || (color1 == 2 && color2 == 1))
			{
				if ((x >= 531 && x <= 631) && (y >= 631  && y <= 731)) // Yellow
				{
					color3 = 3;
					complete = 3;
					if (players == 4)
					{
						color4 = 4;
					}
				}
				else if ((x >= 731 && x <= 831) && (y >= 631  && y <= 731)) //Blue
				{
					color3 = 4;
					complete = 3;
					if (players == 4)
					{
						color4 = 3;
					}
				}			
			
			}
			
			else if ((color1 == 4 && color2 == 3) || (color1 == 3 && color2 == 4))
			{
				if ((x >= 131 && x <= 231) && (y >= 631  && y <= 731)) //Red
				{
					color3 = 1;
					complete = 3;
					if (players == 4)
					{
						color4 = 2;
					}
				}
				else if ((x >= 331 && x <= 431) && (y >= 631  && y <= 731)) //Green
				{
					color3 = 2;
					complete = 3;
					if (players == 4)
					{
						color4 = 1;
					}
				}
			
			}
			
			else if ((color1 == 4 && color2 == 2) || (color1 == 2 && color2 == 4))
			{
				if ((x >= 131 && x <= 231) && (y >= 631  && y <= 731)) //Red
				{
					color3 = 1;
					complete = 3;
					if (players == 4)
					{
						color4 = 3;
					}
				}
				else if ((x >= 531 && x <= 631) && (y >= 631  && y <= 731)) // Yellow
				{
					color3 = 3;
					complete = 3;
					if (players == 4)
					{
						color4 = 1;
					}
				}
						
			}
			
			else if ((color1 == 2 && color2 == 3) || (color1 == 3 && color2 == 2))
			{
				if ((x >= 131 && x <= 231) && (y >= 631  && y <= 731)) //Red
				{
					color3 = 1;
					complete = 3;
					if (players == 4)
					{
						color4 = 4;
					}
				}
				else if ((x >= 731 && x <= 831) && (y >= 631  && y <= 731)) //Blue
				{
					color3 = 4;
					complete = 3;
					if (players == 4)
					{
						color4 = 1;
					}
				}
				
			}
		}
		


		/*COLORS: 1 = RED; 2 = GREEN; 3 = YELLOW; 4 = BLUE*/
		
		if (proceed == 1 && color2 > 0)
		{
			//To proceed to game screen
			if ((x >= 792 && x <= 891) && (y >= 773 && y <= 809))
			{
				game = 1;
				col_check = 0;
			} 
		}
		
		//Clicks on the game board including selection of piece to move on turn
		if (game == 1)
		{
		
			if (next_turn == 1)
			{
				//For moving red goti out of home
				if (turn == 1 && turn_val1 == 6)
				{
					if (((x >= 200 && x <= 247) && (y >= 562 && y <= 607)) && (home[0][0] == 1) && (six < 3))
					{
						pieces[1][1][1] = 452;
						pieces [1][1][2] = 125;
						pieces [1][1][3] = 1;
						board_coords[1][1][1] = 452;
						board_coords[1][1][2] = 715;
						home[0][0] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 308 && x <= 353) && (y >= 562 && y <= 607)) && (home[0][1] == 1) && (six < 3))
					{
						pieces[1][2][1] = 452;
						pieces [1][2][2] = 125;
						pieces [1][2][3] = 1;
						board_coords[1][2][1] = 452;
						board_coords[1][2][2] = 715;
						home[0][1] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 200 && x <= 247) && (y >= 673 && y <= 718)) && (home[0][2] == 1) && (six < 3))
					{
						pieces[1][3][1] = 452;
						pieces [1][3][2] = 125;
						pieces [1][3][3] = 1;
						board_coords[1][3][1] = 452;
						board_coords[1][3][2] = 715;
						home[0][2] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 308 && x <= 353) && (y >= 673 && y <= 718)) && (home[0][3] == 1) && (six < 3))
					{
						pieces[1][4][1] = 452;
						pieces [1][4][2] = 125;
						pieces [1][4][3] = 1;
						board_coords[1][4][1] = 452;
						board_coords[1][4][2] = 715;
						home[0][3] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
				
				}
				//For moving green goti out of home
				else if (turn == 2 && turn_val1 == 6)
				{
					if (((x >= 664 && x <= 707) && (y >= 564 && y <= 606)) && (home[1][0] == 1) && (six < 3))
					{
						pieces[2][1][1] = 802;
						pieces [2][1][2] = 375;
						pieces[2][1][3] = 2;
						board_coords[2][1][1] = 805;
						board_coords[2][1][2] = 467;
						home[1][0] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 764 && x <= 809) && (y >= 564 && y <= 606)) && (home[1][1] == 1) && (six < 3))
					{
						pieces[2][2][1] = 802;
						pieces [2][2][2] = 375;
						pieces[2][2][3] = 2;
						board_coords[2][2][1] = 805;
						board_coords[2][2][2] = 467;
						home[1][1] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 664 && x <= 707) && (y >= 673 && y <= 718))&& (home[1][2] == 1) && (six < 3))
					{
						pieces[2][3][1] = 802;
						pieces [2][3][2] = 375;
						pieces[2][3][3] = 2;
						board_coords[2][3][1] = 805;
						board_coords[2][3][2] = 467;
						home[1][2] = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 764 && x <= 809) && (y >= 673 && y <= 718)) && (home[1][3] == 1) && (six < 3))
					{
						pieces[2][4][1] = 802;
						pieces [2][4][2] = 375;
						pieces[2][4][3] = 2;
						board_coords[2][4][1] = 805;
						board_coords[2][4][2] = 467;
						home[1][3] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}					

				
				}
				
				//For moving yellow goti out of home
				else if (turn == 3 && turn_val1 == 6)
				{
					if (((x >= 664 && x <= 707) && (y >= 112 && y <= 157)) && (home[2][0] == 1) && (six < 3))
					{
						pieces[3][1][1] = 552;
						pieces [3][1][2] = 725;
						pieces [3][1][3] = 3;
						board_coords[3][1][1] = 557;
						board_coords[3][1][2] = 115;
						home[2][0] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 764 && x <= 809) && (y >= 112 && y <= 157)) && (home[2][1] == 1) && (six < 3))
					{
						pieces[3][2][1] = 552;
						pieces [3][2][2] = 725;
						pieces [3][2][3] = 3;
						board_coords[3][2][1] = 557;
						board_coords[3][2][2] = 115;
						home[2][1] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 664 && x <= 707) && (y >= 225 && y <= 268)) && (home[2][2] == 1) && (six < 3))
					{
						pieces[3][3][1] = 552;
						pieces [3][3][2] = 725;
						pieces [3][3][3] = 3;
						board_coords[3][3][1] = 557;
						board_coords[3][3][2] = 115;
						home[2][2] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 764 && x <= 809) && (y >= 225 && y <= 268)) && (home[2][3] == 1) && (six < 3))
					{
						pieces[3][4][1] = 552;
						pieces [3][4][2] = 725;
						pieces [3][4][3] = 3;
						board_coords[3][4][1] = 557;
						board_coords[3][4][2] = 115;
						home[2][3] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
				}
				
				//For moving blue goti out of home
				else if (turn == 4 && turn_val1 == 6)
				{
					if (((x >= 200 && x <= 247) && (y >= 112 && y <= 157)) && (home[3][0] == 1) && (six < 3))
					{
						pieces[4][1][1] = 202;
						pieces [4][1][2] = 475;
						pieces [4][1][3] = 4;
						board_coords[4][1][1] = 204;
						board_coords[4][1][2] = 364;
						home[3][0] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 308 && x <= 353) && (y >= 112 && y <= 157)) && (home[3][1] == 1) && (six < 3))
					{
						pieces[4][2][1] = 202;
						pieces [4][2][2] = 475;
						pieces [4][2][3] = 4;
						board_coords[4][2][1] = 204;
						board_coords[4][2][2] = 364;
						home[3][1] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 200 && x <= 247) && (y >= 225 && y <= 268)) && (home[3][2] == 1) && (six < 3))
					{
						pieces[4][3][1] = 202;
						pieces [4][3][2] = 475;
						pieces [4][3][3] = 4;
						board_coords[4][3][1] = 204;
						board_coords[4][3][2] = 364;
						home[3][2] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
					else if (((x >= 308 && x <= 353) && (y >= 225 && y <= 268)) && (home[3][3] == 1) && (six < 3))
					{
						pieces[4][4][1] = 202;
						pieces [4][4][2] = 475;
						pieces [4][4][3] = 4;
						board_coords[4][4][1] = 204;
						board_coords[4][4][2] = 364;
						home[3][3] = 0;
						turn_val1 = 0;
						next_turn = 0;
						if (six > 2)
							ChangeTurns();
					}
				
				
				}
				
				//Changing turns if all pieces are in home and turn isn't equal to 6
				else if (home[turn-1][0] == 1 && home[turn-1][1] == 1 && home[turn-1][2] == 1 && home[turn-1][3] == 1 && turn_val1 != 6)   
				{
					
					ChangeTurns();
				}
				
				//Execution of movement function for moving piece if it is possible
				if (turn_val1 > 0)
				{
				
					for (int j = 1; j <= 4; j++)
					{
						if ((x >= (board_coords[turn][j][1] - 25) && x <= (board_coords[turn][j][1] + 25)) && (y >= (board_coords[turn][j][2] - 25) && y <= (board_coords[turn][j][2] + 25)))
						{
							movement = 1;
							piece_num = j;
						}
							
					}
					
					if (movement == 1 && home[turn-1][piece_num-1] == 0)
					{

						Movement();
					}
				}
			}
		
		
		}
	}
		
		


	
	 else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
				
	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {


/*-------------------3D ARRAY FOR COORDINATESS-----------------------------*/

	//Red pieces coordinates
	pieces[1][1][1] = 224;
	pieces[1][1][2] = 255;
	pieces[1][1][3] = 0;
	
	initial[1][1][1] = 224;
	initial[1][1][2] = 255;

	pieces[1][2][1] = 329;
	pieces[1][2][2] = 255;
	pieces[1][2][3] = 0;
	
	initial[1][2][1] = 329;
	initial[1][2][2] = 255;

	pieces[1][3][1] = 224;
	pieces[1][3][2] = 146;
	pieces[1][3][3] = 0;
	
	initial[1][3][1] = 224;
	initial[1][3][2] = 146;

	pieces[1][4][1] = 329;
	pieces[1][4][2] = 146;
	pieces[1][4][3] = 0;
	
	initial[1][4][1] = 329;
	initial[1][4][2] = 146;


	//Green Pieces coordinates
	pieces[2][1][1] = 684;
	pieces[2][1][2] = 255;
	pieces[2][1][3] = 0;
	
	initial[2][1][1] = 684;
	initial[2][1][2] = 255;

	pieces[2][2][1] = 785;
	pieces[2][2][2] = 255;
	pieces[2][2][3] = 0;
	
	initial[2][2][1] = 785;
	initial[2][2][2] = 255;

	pieces[2][3][1] = 684;
	pieces[2][3][2] = 146;
	pieces[2][3][3] = 0;	
	
	initial[2][3][1] = 684;
	initial[2][3][2] = 146;					/*-----------------------[][][1] == x-axis, [][][2] == y-axis, [][][3] == direction------------------*/
										

	pieces[2][4][1] = 785;
	pieces[2][4][2] = 146;
	pieces[2][4][3] = 0;
	
	initial[2][4][1] = 785;
	initial[2][4][2] = 146;						/*----------------------[] == color, [] == piece number---------------------------------------------*/


	//Yellow Pieces coordinates
	pieces[3][1][1] = 684;						/*---------------------DIRECTIONS: 1 = upward, 2 = left, 3 = down, 4 = right-------------------------*/
	pieces[3][1][2] = 705;
	pieces[3][1][3] = 0;
	
	initial[3][1][1] = 684;	
	initial[3][1][2] = 705;
	

	pieces[3][2][1] = 785;
	pieces[3][2][2] = 705;
	pieces[3][2][3] = 0;
	
	initial[3][2][1] = 785;
	initial[3][2][2] = 705;
	

	pieces[3][3][1] = 684;
	pieces[3][3][2] = 595;
	pieces[3][3][3] = 0;
	
	initial[3][3][1] = 684;
	initial[3][3][2] = 595;
	

	pieces[3][4][1] = 785;
	pieces[3][4][2] = 595;
	pieces[3][4][3] = 0;
	
	initial[3][4][1] = 785;
	initial[3][4][2] = 595;
	

	//Blue Pieces coordinates
	pieces[4][1][1] = 224;
	pieces[4][1][2] = 705;
	pieces[4][1][3] = 0;
	
	initial[4][1][1] = 224;
	initial[4][1][2] = 705;

	pieces[4][2][1] = 329;
	pieces[4][2][2] = 705;
	pieces[4][2][3] = 0;
	
	initial[4][2][1] = 329;
	initial[4][2][2] = 705;

	pieces[4][3][1] = 224;
	pieces[4][3][2] = 595;
	pieces[4][3][3] = 0;
	
	initial[4][3][1] = 224;
	initial[4][3][2] = 595;

	pieces[4][4][1] = 329;
	pieces[4][4][2] = 595;
	pieces[4][4][3] = 0;
	
	initial[4][4][1] = 329;
	initial[4][4][2] = 595;


/*-------------------3D ARRAY FOR COORDINATESS-----------------------------*/


	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("PF Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
