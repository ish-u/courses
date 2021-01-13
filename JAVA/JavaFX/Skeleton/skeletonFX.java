import javafx.application.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.layout.*;

//All javaFX application are extended from the Application class of the javafx package
//the Application class has 3 methods start()  init() stop() that can be overridden
//all javafx application has a stage and a scence

public class skeletonFX extends Application{
  //main() Class
  public static void main(String args[])
  {
    //this method is in the main application thread( whaterver a thread is idk multithread programming)
    //we use this method to call launch() method which in turns calls the ini() then start() methods
    //stop() method is called when the application is stoppped
    //the javafx application is initialised in the start() method because it is in the application thread (again no idea about a thread)

    launch(args);
  }

  //init() method
  public void init(){
    System.out.println("In the init() method");
  }

  //start() method
  //passing a Stage object reference
  public void start(Stage stage){
    System.out.println("inside start() method");
    //setting the title of the javafx application
    stage.setTitle("my first javaFX Application");
    //creating a root node that will be used to put contents to
    FlowPane rootNode = new FlowPane();
    //creating a scene and adding the rootNode(here flowlayout) too import junit.framework.TestCase;
    Scene scene = new Scene(rootNode,500,500);
    //adding scene to the Stage
    stage.setScene(scene);
    //making the scene visible
    stage.show();
  }

  //stop() method
  public void stop(){
    System.out.println("inside the stop() method");
    System.out.println("Application Terminated");
  }

}
