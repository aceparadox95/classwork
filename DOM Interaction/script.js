//Selects the cell by outlining the cell
//Also temporarily sets the id of the cell selected
function select(coords){
	var tbl = document.getElementById("maintable");
	//Used comments on Piazza to get the syntax to access the table elements
	tbl.children[1].children[coords.y].children[coords.x].style.border = '3px solid black';
	tbl.children[1].children[coords.y].children[coords.x].id = "selected"
}
//Checks to make sure the selected cell isn't trying to move out of the table
function moveValidate(coords){
	if ((coords.x >= 0 && coords.x <= 3) && (coords.y >= 0 && coords.y <= 3)){
		var selected = document.getElementById("selected");
		selected.id ="";
		selected.style.border = '1px solid black';
		return true;
	}
	else{
		return false;
	}
}
//highlights the selected cell based on its id
function highlight(){
	var selected = document.getElementById("selected");
	var selectX = (selected.getAttribute("x")*1);
	var selectY = (selected.getAttribute("y")*1);
	tbl.children[1].children[selectY].children[selectX].style.backgroundColor = 'yellow';
}
//moves selected cell to the left
function moveLeft(){
	var selected = document.getElementById("selected");
	var newX = (selected.getAttribute("x")*1) - 1;
	var newY = (selected.getAttribute("y")*1);
	newCoords = {x:newX, y:newY}
	if (moveValidate(newCoords)){
		select(newCoords);
	}
}
//moves selected cell to the right
function moveRight(){
	var selected = document.getElementById("selected");
	var newX = (selected.getAttribute("x")*1) + 1;
	var newY = (selected.getAttribute("y")*1);
	newCoords = {x:newX, y:newY}
	if (moveValidate(newCoords)){
		select(newCoords);
	}
}
//moves the selected cell up
function moveUp(){
	var selected = document.getElementById("selected");
	var newX = (selected.getAttribute("x")*1);
	var newY = (selected.getAttribute("y")*1) - 1;
	newCoords = {x:newX, y:newY}
	if (moveValidate(newCoords)){
		select(newCoords);
	}
}
//moves the selected cell down
function moveDown(coords){
	var selected = document.getElementById("selected");
	var newX = (selected.getAttribute("x")*1);
	var newY = (selected.getAttribute("y")*1) + 1;
	newCoords = {x:newX, y:newY}
	if (moveValidate(newCoords)){
		select(newCoords);
	}
}
//Generate the table on document load
var tbl = document.createElement("table");
tbl.id = "maintable";
var tblBody = document.createElement("tbody");
var tblHead = document.createElement("thead");
tbl.style.border = '1px solid black';

//Generate the table headers
var tblHeaderRow = document.createElement("tr");
for (var i=1; i<5; i++){
	var tblHeader = document.createElement("th");
	tblHeader.textContent = "Header " + i;
	tblHeader.style.border = '1px solid black';
	tblHeaderRow.appendChild(tblHeader);
}
tblHead.appendChild(tblHeaderRow);
tbl.appendChild(tblHead);

//Generate the table body cells
for (var i=1; i<5; i++){
	var tblRow = document.createElement("tr")
	for (var j=1; j<5; j++){
			var tblBlankCell = document.createElement("td");
			tblBlankCell.setAttribute("y", i-1); //custom attribute to keep track of cell position
			tblBlankCell.setAttribute("x", j-1); //custom attribute to keep track of cell position
			tblBlankCell.textContent = i + ", " + j;
			tblBlankCell.style.border = '1px solid black';
			tblRow.appendChild(tblBlankCell);
	}
	tblBody.appendChild(tblRow);
}

//Attaching the table to the body
tbl.appendChild(tblBody);
tbl.style.borderStyle = 'solid';
document.body.appendChild(tbl);

//Selecting the top left cell at startup
var origCoords = {x:0, y:0};
select(origCoords);


//Creating Buttons
lftBtn = document.createElement("button");
rgtBtn = document.createElement("button");
upBtn = document.createElement("button");
dnBtn = document.createElement("button");
mrkBtn = document.createElement("button");

//Populating Buttons
lftBtn.textContent = "Left";
lftBtn.id = "L";
rgtBtn.textContent = "Right";
rgtBtn.id = "R";
upBtn.textContent = "Up";
upBtn.id = "U";
dnBtn.textContent = "Down";
dnBtn.id = "D";
mrkBtn.textContent = "Mark Cell";
mrkBtn.id = "marker";

//Attaching buttons to page
document.body.appendChild(lftBtn);
document.body.appendChild(rgtBtn);
document.body.appendChild(upBtn);
document.body.appendChild(dnBtn);
document.body.appendChild(mrkBtn);

//Wiring buttons to functions
document.getElementById("L").addEventListener("click", moveLeft);
document.getElementById("R").addEventListener("click", moveRight);
document.getElementById("U").addEventListener("click", moveUp);
document.getElementById("D").addEventListener("click", moveDown);
document.getElementById("marker").addEventListener("click", highlight);
