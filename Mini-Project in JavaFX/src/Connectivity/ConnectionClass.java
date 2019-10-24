package Connectivity;

//importing required package
import java.sql.*;

public class ConnectionClass
{
    public Connection connection;
    public Connection getConnection()  //method
    {
        String dbname="miniproject";  //Database Name stored in MySQL
        String un="root";  //MySQL UserName
        String pw="MySQL@nor00t";  //MySQL Password
        try
        {
            Class.forName("com.mysql.cj.jdbc.Driver");  // used for using external configuration file
            connection=DriverManager.getConnection("jdbc:mysql://localhost:3307/"+dbname,un,pw);  //location of MySQL Server or URL
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        return connection;
    }
}
