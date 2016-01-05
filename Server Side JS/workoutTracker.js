var express = require('express');
var app = express();
app.use(express.static('public'));
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var mysql = require('mysql');
var bodyParser = require('body-parser');
var workoutPool = mysql.createPool({
  host  : 'localhost',
  user  : 'student',
  password: 'default',
  database: 'student'
});

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 2997);


app.get('/',function(req,res,next){
  var context = {};
  workoutPool.query('SELECT * FROM workouts', function(err, rows, fields){
    if(err){
      next(err);
      return;
    }
    var queryResString = JSON.stringify(rows);
    context.resultstbl = JSON.parse(queryResString);
	console.log(context.resultstbl);
    res.render('workout', context);
  });
});

app.get('/insert',function(req,res,next){
  var context = {};
  console.log(req.query);
  workoutPool.query("INSERT INTO workouts (name, reps, weight, date, lbs) VALUES (?, ?, ?, ?, ?)", [req.query.wName, req.query.wReps, req.query.wWeight, req.query.wDate, req.query.wWeightType], function(err, result){
    if(err){
      next(err);
      return;
    }
    context.results = "Inserted id " + result.insertId;
    //res.render('workout',context);
	workoutPool.query('SELECT * FROM workouts', function(err, rows, fields){
		if(err){
		  next(err);
		  return;
		}
		var queryResString = JSON.stringify(rows);
		context.resultstbl = JSON.parse(queryResString);
		console.log(context.resultstbl);
		res.render('workout', context);
	});
  });
});

app.get('/delete',function(req,res,next){
  var context = {};
  console.log(req.query);
  workoutPool.query("DELETE FROM workouts WHERE id = ?", [req.query.delID], function(err, result){
    if(err){
      next(err);
      return;
    }
    context.results = "Record #" + [req.query.delID] + " deleted";
    //res.render('workout',context);
	workoutPool.query('SELECT * FROM workouts', function(err, rows, fields){
		if(err){
		  next(err);
		  return;
		}
		var queryResString = JSON.stringify(rows);
		context.resultstbl = JSON.parse(queryResString);
		console.log(context.resultstbl);
		res.render('workout', context);
	});
  });
});

app.get('/update',function(req,res,next){
  var context = {};
  console.log(req.query);
  workoutPool.query("UPDATE workouts SET name=?, reps=?, weight=?,date=?,lbs=? WHERE id=?", [req.query.wName, req.query.wReps, req.query.wWeight, req.query.wDate, req.query.wWeightType, req.query.wID], function(err, result){
    if(err){
      next(err);
      return;
    }
    context.results = "Record #" + [req.query.wID] + " updated";
    //res.render('workout',context);
	workoutPool.query('SELECT * FROM workouts', function(err, rows, fields){
		if(err){
		  next(err);
		  return;
		}
		var queryResString = JSON.stringify(rows);
		context.resultstbl = JSON.parse(queryResString);
		console.log(context.resultstbl);
		res.render('workout', context);
	});
  });
});

app.get('/edit',function(req,res,next){
  var context = {};
  workoutPool.query('SELECT * FROM workouts WHERE id=?',[req.query.edID], function(err, rows, fields){
    if(err){
      next(err);
      return;
    }
    var queryResString = JSON.stringify(rows);
	var newDate = JSON.parse(queryResString);
	newDate[0].date = fixDate(newDate[0].date);
    context.editrec = newDate;
	console.log(context.editrec);
    res.render('edit', context);
  });
});

app.get('/reset-table',function(req,res,next){
  var context = {};
  workoutPool.query("DROP TABLE IF EXISTS workouts", function(err){
    var createQueryString = "CREATE TABLE workouts("+
    "id INT PRIMARY KEY AUTO_INCREMENT,"+
    "name VARCHAR(255) NOT NULL,"+
    "reps INT,"+
    "weight INT,"+
    "date DATE,"+
    "lbs BOOLEAN)";
	console.log(createQueryString);
    workoutPool.query(createQueryString, function(err){
      context.results = "Table reset";
      res.render('workout',context);
    })
  });
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

function fixDate(date){
	var newDate = date.substring(0,10);
	console.log("youmade it in here" + newDate);
	return newDate;
}
