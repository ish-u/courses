import javafx.application.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;

public class labelTest extends Application{
  //message to be displayed on
  String message;
  //main()
  public static void main(String args[]){
    launch(args);
  }
  //start()
  public void start(Stage stage){
      FlowPane rootNode = new FlowPane();
      Scene scene = new Scene(rootNode,500,500);
      stage.setScene(scene);
      Label label = new Label(" This is a label in javaFX ");
      //we use getChildren() method to get a list of all the children of a node
      //then use add() method to add anything to the node
      rootNode.getChildren().add(label);
      stage.show();
  }
}
