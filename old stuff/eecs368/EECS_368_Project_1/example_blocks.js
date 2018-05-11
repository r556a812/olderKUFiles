//***********************************************************
//** TETRIS - MOVING BLOCKS AROUND
//***********************************************************

// This example demonstrates how blocks can be grouped and 
// draw individually each time GetCurrentState is called.

tetrisGame = {};
tetrisGame.currentState = [];
tetrisGame.shapes = [];

var DIR_LT = 1;
var DIR_RT = 2;
var DIR_UP = 3;
var DIR_DN = 4;

tetrisGame.AddShape = function(){
	// Don't care about adding more shapes
}

tetrisGame.IncrementTime = function(){
	// If there are no shapes then add 3 at the center
	if(this.shapes.length == 0){
		this.shapes.push({'type' : 4, 'center' : 105});
		this.shapes.push({'type' : 1, 'center' : 105});
		this.shapes.push({'type' : 5, 'center' : 105});
	}
	
	// Move each block in a random direction
	for(var i = 0; i < this.shapes.length; i++){
		var currentShape = this.shapes[i];
		
		// Generate a random number between 1 and 4
		var dir = Math.floor((Math.random() * 4) + 1);
		
		switch(dir){
			case DIR_UP:	// Move down (subtract 10 from center)
				currentShape.center -= 10;
				break;
			case DIR_DN:	// Move up (add 10 to center)
				currentShape.center += 10;
				break;
			case DIR_LT:	// Move left (subtract 1 from center)
				currentShape.center -= 1;
				break;
			case DIR_RT:	// Move right (add 1 to center)
				currentShape.center += 1;
				break;
		}
		
		while(currentShape.center < 10){	// Keep the blocks from leaving through the top
			currentShape.center += 10;
		}
		while(currentShape.center > 200){ 	// Keep the blocks from leaving through the bottom
			currentShape.center -= 10;
		}
		
		var withinRow = currentShape.center % 10;
		while(withinRow > 7){				// Keep the blocks from leaving through the right side
			currentShape.center -= 1;
			withinRow = currentShape.center % 10;
		}	
		while(withinRow < 2){				// Keep the blocks from leaving through the left side
			currentShape.center += 1;
			withinRow = currentShape.center % 10;
		}
	}
	
	
}

tetrisGame.GetCurrentState = function(){
	// This is where we display our image to the screen
	// Whatever we return in our 1-dimensional array is shown 
	// on the tetris board. 

	// Clear the board
	this.currentState = [];
	for(var r = 0; r < 20; r++){
		for(var c = 0; c < 10; c++){
			this.currentState.push(-1);
		}
	}
	
	
	for(var i = 0; i < this.shapes.length; i++){
		this.DrawShape(this.shapes[i]);
	}
	
	
	return this.currentState;
}

tetrisGame.IsShapeFalling = function(){
	// Always just return true so that we can keep getting
	// increment time calls.
	return true;
}

tetrisGame.DrawShape = function(shape){
	// Draw center pixels
	this.currentState[shape.center] = shape.type;
	this.currentState[shape.center - 10] = shape.type;
	
	// Draw left pixels
	this.currentState[shape.center - 1] = shape.type;
	this.currentState[shape.center - 2] = shape.type;
	this.currentState[shape.center - 2 - 10] = shape.type;
	
	// Draw right pixels
	this.currentState[shape.center + 1] = shape.type;
	this.currentState[shape.center + 2] = shape.type;
	this.currentState[shape.center + 2 - 10] = shape.type;
	
	
}