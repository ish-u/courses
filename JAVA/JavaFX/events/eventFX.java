import javafx.application.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;

public class eventFX extends Application{
  public static void main(String args[]){
    launch(args);
  }
  public void start(Stage stage){
    FlowPane rootNode = new FlowPane(20,20);
    rootNode.setAlignment(Pos.CENTER);
    Scene scene = new Scene(rootNode,300,300);
    stage.setScene(scene);
    Label label = new Label("...");

    //adding a Button(text based) to Scene
    Button btn = new Button("HELLO");

    //event handling
    btn.setOnAction(new EventHandler<ActionEvent>(){
      public void handle(ActionEvent e){
        label.setText(" Supp BITCH...? ");
      }
    });

    rootNode.getChildren().addAll(btn,label);
    stage.show();

  }
}
