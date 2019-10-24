module FinalMP
{
    requires javafx.fxml;  //for fxml file
    requires javafx.controls;  //for using controls in javafx
    requires java.sql;  //it is used for MySQL Queries and Syntax related to it in Java
    requires kotlin.stdlib;  // kotlin is use as it makes it more easy and conventional for extension of program with other jar files and other syntax
    opens sample;
}

// needed for executing javaFX frame
// requires is used for importing libraries in program
// need to download appropriate kotlin.stdlib library according to IDE
