package sample;

//importing required package
import Connectivity.ConnectionClass;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.stage.Stage;
import java.io.IOException;
import java.net.URL;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ResourceBundle;


public class Controller1 implements Initializable
{
    public static String uname,pword;  //declaring variables
    @FXML
    public Button cnu,login,show,hide;  //declaring variables
    @FXML
    public TextField username,motext,cpw;  //declaring variables
    @FXML
    public PasswordField password;  //declaring variables
    @FXML
    public Label moprompt,prompt,punch,dbfname,dbmname,dblname,dbage,dbcontact,dbdob,dbgender,dbemail,dname,dgender,dage,dcontact,demail,ddob;  //declaring variables
    @FXML
    public RadioButton r1,r2,sdetail;  //declaring variables
    Stage stage1 = new Stage();
    Stage stage2 = new Stage();
    Stage stage3 = new Stage();

    @FXML
    void newwindow(ActionEvent event2)
    {
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("screen2.fxml"));  //for loading corresponding FXML file in new window
        try
        {
            Parent root1 = (Parent) fxmlLoader.load();
            //for opening new window
            Stage stage = new Stage();
            stage.setTitle("Create User");
            stage.setScene(new Scene(root1));
            stage.show();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        System.out.println("Create User Frame Executed...");
    }

    @FXML
    public void login(ActionEvent event)
    {
        ConnectionClass connectionClass=new ConnectionClass();  //created object of ConnectionClass and getting connection with MySQL
        Connection connection=connectionClass.getConnection();
        if(username.getText().trim().isEmpty())
        {
            prompt.setText("User Name is Empty...");  //to prompt if input box is empty
        }
        else if(password.getText().trim().isEmpty())
        {
            prompt.setText("Password Field is Empty...");  //to prompt if input box is empty
        }
        else
        {
            try
            {
                Statement statement = connection.createStatement();
                //query of MySQL for getting values from database
                String sql = "select * from info where UserID='" + username.getText() + "' and Password='" + password.getText() + "';";
                ResultSet resultSet = statement.executeQuery(sql);
                uname=username.getText();
                pword=password.getText();
                if (resultSet.next())  //for checking username and password in database
                {
                    prompt.setText("Logged In");
                    FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("screen3.fxml"));  //for loading corresponding FXML file in new window
                    try
                    {
                        Parent root1 = (Parent) fxmlLoader.load();
                        //for opening new window
                        stage1.setTitle("Welcome "+username.getText());
                        stage1.setScene(new Scene(root1));
                        stage1.show();
                    }
                    catch (IOException e)
                    {
                        e.printStackTrace();
                    }
                }
                else
                {
                    prompt.setText("Invalid Credential");
                }
                password.setText(""); //for clearing textbox
            }
            catch (SQLException e)
            {
                e.printStackTrace();
            }
            System.out.println("Login Window...");
        }
    }

    public void punchin(ActionEvent event)
    {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("hh:mm:ss a, EEE dd/MM/yyyy");
        LocalDateTime now = LocalDateTime.now();  //to get date and time of system
        punch.setText("Punched In at : "+dtf.format(now));
        ConnectionClass connectionClass=new ConnectionClass();  //created object of ConnectionClass and getting connection with MySQL
        Connection connection=connectionClass.getConnection();
        //query of MySQL for inserting values into database
        String sql="insert into punch values(null,'"+uname+"','PunchIN : "+dtf.format(now)+"');";
        Statement statement = null;
        try //for executing query of MySQL
        {
            statement = connection.createStatement();
            statement.executeUpdate(sql);
        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }
        r1.setDisable(true);  //disabling radio button once it's used
        r2.setDisable(true);  //disabling radio button once it's used
    }

    public void punchout(ActionEvent event)
    {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("hh:mm:ss a, EEE dd/MM/yyyy");
        LocalDateTime now = LocalDateTime.now();  //to get date and time of system
        punch.setText("Punched Out at : "+dtf.format(now));
        ConnectionClass connectionClass=new ConnectionClass();  //created object of ConnectionClass and getting connection with MySQL
        Connection connection=connectionClass.getConnection();
        //query of MySQL for inserting values into database
        String sql="insert into punch values(null,'"+uname+"','PunchOUT : "+dtf.format(now)+"');";
        Statement statement = null;
        try //for executing query of MySQL
        {
            statement = connection.createStatement();
            statement.executeUpdate(sql);
        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }
        r1.setDisable(true);  //disabling radio button once it's used
        r2.setDisable(true);  //disabling radio button once it's used
    }

    public void details(ActionEvent event)
    {
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("screen4.fxml"));  //for loading corresponding FXML file in new window
        try
        {
            System.out.println("Detail Frame Executed...");
            //for opening new window
            Parent root1 = (Parent) fxmlLoader.load();
            stage2.setTitle("Create User");
            stage2.setScene(new Scene(root1));
            stage2.show();
        }
        catch (IOException e)
        {
           e.printStackTrace();
        }
    }

    public void Display(ActionEvent event)
    {
        System.out.println("Showing User Information...");
        ConnectionClass connectionClass=new ConnectionClass();  //created object of ConnectionClass and getting connection with MySQL
        Connection connection=connectionClass.getConnection();
        Statement statement = null;
        try
        {
            statement = connection.createStatement();
            //query of MySQL for getting values from database
            String sql = "select * from info where UserID='" + uname + "' and Password='" + pword + "';";
            ResultSet resultSet = statement.executeQuery(sql);
            if (resultSet.next())
            {
                dbfname.setText(resultSet.getString("FirstName"));
                dbmname.setText(resultSet.getString("MiddleName"));
                dblname.setText(resultSet.getString("LastName"));
                dbage.setText(resultSet.getString("Age"));
                dbgender.setText(resultSet.getString("Gender"));
                dbcontact.setText(resultSet.getString("ContactNo"));
                dbemail.setText(resultSet.getString("EmailID"));
                dbdob.setText(resultSet.getString("DOB"));
                dname.setText("Employee Name");
                dgender.setText("Gender");
                dage.setText("Age");
                ddob.setText("D.O.B.");
                dcontact.setText("Contact No.");
                demail.setText("Email ID");
            }
        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }
    }

    public void modify(ActionEvent event)
    {
        dbfname.setText("");dbmname.setText("");dblname.setText("");dbage.setText("");dbgender.setText("");dbcontact.setText(""); //for clearing textbox
        dbemail.setText("");dbdob.setText("");dname.setText("");dage.setText("");dcontact.setText("");ddob.setText("");dgender.setText("");demail.setText(""); //for clearing textbox
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("screen5.fxml"));  //for loading corresponding FXML file in new window
        try
        {
            System.out.println("Modification Frame Executed...");
            //for opening new window
            Parent root1 = (Parent) fxmlLoader.load();
            stage3.setTitle("Modification of ");
            stage3.setScene(new Scene(root1));
            stage3.show();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public void moage()
    {
        if(motext.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            moprompt.setText("Enter Corresponding Entries...");
        }
        else
        {
            if(cpw.getText().equals(pword))
            {
                ConnectionClass connectionClass = new ConnectionClass();  //created object of ConnectionClass and getting connection with MySQL
                Connection connection = connectionClass.getConnection();
                Statement statement = null;
                //query of MySQL for updating values in database
                String sql = "update info set Age='" + motext.getText() + "' where UserID='" + uname + "';";
                try  //for executing query of MySQL
                {
                    statement = connection.createStatement();
                    statement.executeUpdate(sql);
                    moprompt.setText("Succesfully modified Age...");
                }
                catch (SQLException e)
                {
                    e.printStackTrace();
                }
            }
            else
            {
                moprompt.setText("Current Password Enter is Wrong...");
            }
        }
        cpw.setText(""); //for clearing textbox
    }

    public void moemail()
    {
        if(motext.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            moprompt.setText("Enter Corresponding Entries...");
        }
        else
        {
            if(cpw.getText().equals(pword))
            {
                ConnectionClass connectionClass = new ConnectionClass();  //created object of ConnectionClass and getting connection with MySQL
                Connection connection = connectionClass.getConnection();
                Statement statement = null;
                //query of MySQL for updating values in database
                String sql = "update info set EmailID='" + motext.getText() + "' where UserID='" + uname + "';";
                try //for executing query of MySQL
                {
                    statement = connection.createStatement();
                    statement.executeUpdate(sql);
                    moprompt.setText("Succesfully modified Email...");
                }
                catch (SQLException e)
                {
                    e.printStackTrace();
                }
            }
            else
            {
                moprompt.setText("Current Password Enter is Wrong...");
            }
        }
        cpw.setText(""); //for clearing textbox
    }

    public void mocontact()  //to prompt if input box is empty
    {
        if(motext.getText().trim().isEmpty())
        {
            moprompt.setText("Enter Corresponding Entries...");
        }
        else
        {
            if(cpw.getText().equals(pword))
            {
                ConnectionClass connectionClass = new ConnectionClass();  //created object of ConnectionClass and getting connection with MySQL
                Connection connection = connectionClass.getConnection();
                Statement statement = null;
                //query of MySQL for updating values in database
                String sql = "update info set ContactNo='" + motext.getText() + "' where UserID='" + uname + "';";
                try //for executing query of MySQL
                {
                    statement = connection.createStatement();
                    statement.executeUpdate(sql);
                    moprompt.setText("Succesfully modified Contact Number...");
                }
                catch (SQLException e)
                {
                    e.printStackTrace();
                }
            }
            else
            {
                moprompt.setText("Current Password Enter is Wrong...");
            }
        }
        cpw.setText(""); //for clearing textbox
    }

    public void mopassword()
    {
        if(motext.getText().trim().isEmpty())  //to prompt if input box is empty
        {
            moprompt.setText("Enter Corresponding Entries...");
        }
        else
        {
            if(cpw.getText().equals(pword))
            {
                ConnectionClass connectionClass = new ConnectionClass();  //created object of ConnectionClass and getting connection with MySQL
                Connection connection = connectionClass.getConnection();
                Statement statement = null;
                //query of MySQL for updating values in database
                String sql = "update info set Password='" + motext.getText() + "' where UserID='" + uname + "';";
                try //for executing query of MySQL
                {
                    statement = connection.createStatement();
                    statement.executeUpdate(sql);
                    moprompt.setText("Succesfully modified Password...");
                }
                catch (SQLException e)
                {
                    e.printStackTrace();
                }
            }
            else
            {
                moprompt.setText("Current Password Enter is Wrong...");
            }
        }
        cpw.setText(""); //for clearing textbox
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle)
    {

    }

}
