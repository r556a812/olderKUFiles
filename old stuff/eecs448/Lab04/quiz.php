<?php

    $answer1 = $_POST["mascot"];
    $answer2 = $_POST["capital"];
    $answer3 = $_POST["flower"];
    $answer4 = $_POST["coach"];
    $answer5 = $_POST["number"];
    
    $correct = 0;
    
    if ($answer1 == "Jayhawk") {
        $correct++;
    }
    
    if ($answer2 == "Topeka") {
        $correct++;
    }
    
    if ($answer3 == "Sunflower") {
        $correct++;
    }
    
    if ($answer4 == "Bill Self") {
        $correct++;
    }
    
    if ($answer5 == "5") {
        $correct++;
    }

    $grade = ($correct/5)*100;
    
    echo "Question 1: What is the KU mascot?<br>You answered: ".$answer1."<br>Correct answer: Jayhawk<br><br>
            Question 2: What is the capital of Kansas?<br>You answered: ".$answer2."<br>Correct answer: Topeka<br><br>
            Question 3: What is the state flower for Kansas?<br>You answered: ".$answer3."<br>Correct answer: Sunflower<br><br>
            Question 4: Who is the KU basketball head coach?<br>You answered: ".$answer4."<br>Correct answer: Bill Self<br><br>
            Question 5: Which answer is the number '5'?<br>You answered: ".$answer5."<br>Correct answer: 5<br><br>
            Right Answers: ".$correct."<br>Score: ".$grade."%";
    
?>