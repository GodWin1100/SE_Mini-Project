package sample;

//importing required package
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

//Main class which will execute the program
public class Main extends Application
{
    @Override
    public void start(Stage primaryStage) throws Exception
    {
        System.out.println("Main Frame Executed...");
        //for opening new window
        Parent root = FXMLLoader.load(getClass().getResource("screen1.fxml"));  //for loading corresponding FXML file in new window
        primaryStage.setTitle("Mini Project Company");
        primaryStage.setScene(new Scene(root, 1000, 600));
        primaryStage.show();
    }
    public static void main(String[] args)
    {
        launch(args);
    }
}
