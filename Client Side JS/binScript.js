/*  var apiKey = 'fa7d80c48643dfadde2cced1b1be6ca1';
document.addEventListener('DOMContentLoaded', bindButtons);
function bindButtons(){
	document.getElementById('urlSubmit').addEventListener('click', function(event){
	var req = new XMLHttpRequest();
	var zipCode = document.getElementById('zip').value;
	var inpCity = document.getElementById('city').value;
	var inpState = document.getElementById('state').value;
	if (zipCode > 0){
		req.open("GET", "http://api.openweathermap.org/data/2.5/weather?zip=" + zipCode + ",US" + "&appid=" + apiKey, true);
	}
	else{
		req.open("GET", "http://api.openweathermap.org/data/2.5/weather?q=" + inpCity + "," + inpState + "&appid=" + apiKey, true);
	}
	req.addEventListener('load',function(){
		if(req.status >= 200 && req.status < 400){
			var responseObject = JSON.parse(req.responseText);
			var tempF = (responseObject.main.temp) * (9/5) - 459.67;
			document.getElementById('cityDisp').textContent = "City: " + responseObject.name;
			document.getElementById('temp').textContent = "Temperature(Fahrenheit): " + tempF;
			document.getElementById('humidity').textContent = "Humidity: " + responseObject.main.humidity;
		}
		else{
			console.log("Error in network request" + request.statusText);
		}});
		req.send(null);
		event.preventDefault();
		});
}  */

document.addEventListener('DOMContentLoaded', bindButtons);
function bindButtons(){
document.getElementById('urlSubmit').addEventListener('click', function(event){
    var req = new XMLHttpRequest();
    var payload = {zipCode:0, fName:"", lName:""};
	payload.zipCode = document.getElementById('zip').value;
	payload.fName = document.getElementById('first').value;
	payload.lName = document.getElementById('last').value;
    req.open('POST', 'http://httpbin.org/post', true);
    req.setRequestHeader('Content-Type', 'application/json');
    req.addEventListener('load',function(){
      if(req.status >= 200 && req.status < 400){
        var response = JSON.parse(req.responseText);
		document.getElementById('firstOut').textContent = "This is the response back from httpbin: Hi " + response.json.fName;
		document.getElementById('lastOut').textContent = response.json.lName;
		document.getElementById('zipOut').textContent = " from " + response.json.zipCode;
      } else {
        console.log("Error in network request: " + req.statusText);
      }});
    req.send(JSON.stringify(payload));
    event.preventDefault();
  });
}