var express = require('express');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 2999);

app.get('/',function(req,res){
  res.render('home.handlebars') //We can omit the .handlebars extension as we do below
});


app.get('/get-post-check',function(req,res){
  var queryParams = [];//object array to store input from user
  for (var parameter in req.query){ //pulls each input variable from the form
    queryParams.push({'name':parameter,'value':req.query[parameter]})
  }
  var context = {};
  context.type = "GET Request"; //JSON Object Variable to store the request type
  context.dataList = queryParams; // list of inputs as gathered from the user attahed to JSON object
  res.render('get-post-check', context);
});

app.post('/get-post-check', function(req,res){
  var queryParams = []; //object array to store input from user
  for (var parameter in req.body){ //pulls each input variable from the form
    queryParams.push({'name':parameter,'value':req.body[parameter]})
  }
  //console.log(queryParams);
  //console.log(req.body);
  var context = {}; //empty JSON object to pass to the handlebar view
  context.type = "POST Request"; //JSON Object Variable to store the request type
  context.dataList = queryParams; // list of inputs as gathered from the user attahed to JSON object
  res.render('get-post-check', context);
});

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.type('plain/text');
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});

