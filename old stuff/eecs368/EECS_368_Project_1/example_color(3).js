tetrisGame = {};
tetrisGame.currentState = [];
tetrisGame.initialized = false;
tetrisGame.falling = false;
tetrisGame.dotLocation = 0;

tetrisGame.AddShape = function(shapeType, position, id){
	// Instead of adding the shape based on the type,position, and id,
	// this code is just adding a dot and moving it around. You will
	// need to add real tetris shapes instead.
	AddToConsole("Need to add shape with type = {"+shapeType+"}, position = {"+position+"}, and id = {" + id + "}");
	
	if(!this.initialized){this.Initialize();}
	this.dotLocation = 0;
	this.falling = true;
	this.currentState[this.dotLocation] = 1;
}

tetrisGame.IncrementTime = function(){
	if(!this.initialized){this.Initialize();}
	
	// Get the color
	var color = this.currentState[this.dotLocation];
	
	// Increment the color
	color++;
	if(color > 6){
		color = 0;
	}

	
	// Set the current position of the dot to be empty
	this.currentState[this.dotLocation] = -1;
	if(this.dotLocation + 1 == this.currentState.length){
		this.falling = false;
		return;
	}
	
	// Move the dotLocation
	this.dotLocation = this.dotLocation + 1;
	
	// Set the new current position of the dot to be filled
	this.currentState[this.dotLocation] = color;
	
	
}

tetrisGame.GetCurrentState = function(){
	if(!this.initialized){this.Initialize();}
	return this.currentState;
}

tetrisGame.IsShapeFalling = function(){
	if(!this.initialized){this.Initialize();}
	return tetrisGame.falling;
}

tetrisGame.Initialize = function(){
	for(var i = 0; i < 10; i++){
		for(var j = 0; j < 20; j++){
			this.currentState.push(-1);
		}
	}
	this.initialized = true;
}

