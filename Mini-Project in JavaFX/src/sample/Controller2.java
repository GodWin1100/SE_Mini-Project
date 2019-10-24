package sample;

//importing required package
import Connectivity.ConnectionClass;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

//used for screen2 i.e. for creating new user frame
public class Controller2
{
    @FXML
    public TextField tffname,tfmname,tflname,tfuser,tfpw,tfage,tfemail,tfcontact,gender;  //declaring variables
    @FXML
    public Button submit;  //declaring variables
    @FXML
    public Label alert;  //declaring variables
    @FXML
    public DatePicker dob;  //declaring variables
    Statement statement=null;
    public void create(ActionEvent event)
    {
        if(tffname.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            alert.setText("Enter First Name...");
        }
        else if(tfmname.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            alert.setText("Enter Middle Name...");
        }
        else if (tflname.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            alert.setText("Enter Last Name...");
        }
        else if(tfcontact.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            alert.setText("Enter Contact Number...");
        }
        else if(tfemail.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            alert.setText("Enter Email...");
        }
        else if(tfage.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            alert.setText("Enter Age...");
        }
        else if(gender.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            alert.setText("Enter Gender...");
        }
        else if(dob.getValue()==null)  //to prompt if input box is empty
        {
        alert.setText("Select Date Of Birth");
        }
        else if(tfuser.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            alert.setText("Enter User Name...");
        }
        else if(tfpw.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            alert.setText("Enter Password...");
        }
        else
        {
            ConnectionClass connectionClass = new ConnectionClass();  //created object of ConnectionClass and getting connection with MySQL
            Connection connect = connectionClass.getConnection();
            //query of MySQL for inserting values into database
            String sql = "insert into info values(null,'" + tffname.getText() + "','" + tfmname.getText() + "','" + tflname.getText() + "','" + tfuser.getText() + "','" + tfpw.getText() + "','"+gender.getText()+"','"+dob.getValue()+"','" + tfage.getText() + "','" + tfemail.getText() + "','" + tfcontact.getText() + "');";
            try //for executing query of MySQL
            {
                statement = connect.createStatement();
                statement.executeUpdate(sql);
            }
            catch (SQLException e)
            {
                e.printStackTrace();
            }
            alert.setText("Succesfully Created !!!");
            System.out.println("New User Created...");
        }
    }
}

