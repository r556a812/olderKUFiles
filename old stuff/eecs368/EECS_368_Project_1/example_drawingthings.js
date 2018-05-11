//***********************************************************
//** TETRIS - HOW TO DISPLAY THINGS
//***********************************************************

// This example doesn't include an update loop, it just displays
// a static set of pixels on the display. Your code will need to 
// use similar steps to display the blocks in their correct 
// locations.

tetrisGame = {};
tetrisGame.currentState = [];

tetrisGame.AddShape = function(){
	// Don't care about adding more shapes
}

tetrisGame.IncrementTime = function(){
	// Nothing changes so never do anything here
}

tetrisGame.GetCurrentState = function(){
	// This is where we display our image to the screen
	// Whatever we return in our 1-dimensional array is shown 
	// on the tetris board. 
	
	// Fill the board with empty pixels
	if(this.currentState.length == 0){
		for(var r = 0; r < 20; r++){
			for(var c = 0; c < 10; c++){
				this.currentState.push(-1);
			}
		}
	}
	
	// Put a purple block in the top left corner
	this.currentState[0] = 5;
	
	// Put a light blue shape along the top two rows
	this.currentState[4] = 2;
	this.currentState[5] = 2;
	this.currentState[6] = 2;
	this.currentState[15] = 2;
	
	// Put a straight line across the middle of the board
	this.currentState[50] = 3;
	this.currentState[51] = 3;
	this.currentState[52] = 3;
	this.currentState[53] = 3;
	this.currentState[54] = 3;
	this.currentState[55] = 3;
	this.currentState[56] = 3;
	this.currentState[57] = 3;
	this.currentState[58] = 3;
	this.currentState[59] = 3;
	
	
	return this.currentState;
}

tetrisGame.IsShapeFalling = function(){
	// Always just return true so that nothing ever changes
	return true;
}