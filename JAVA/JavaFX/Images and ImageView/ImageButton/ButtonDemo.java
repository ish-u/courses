import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.control.*;
import javafx.scene.image.*;
import javafx.scene.layout.*;
import javafx.event.*;
import javafx.geometry.*;


public class ButtonDemo extends Application
{
    public static void main(String args[])
    {
        launch(args);
    }

    //overriding the start() methods
    public void start(Stage myStage)
    {
        myStage.setTitle("BUTTON DEMO");
        FlowPane rootNode = new FlowPane();
        rootNode.setAlignment(Pos.CENTER);
        Scene myScene = new Scene(rootNode, 800, 800);
        myStage.setScene(myScene);

        Label label = new Label("");
        Button btn = new Button("SKY",new ImageView("sky.jpg"));
        btn.setContentDisplay(ContentDisplay.TOP);
        btn.setOnAction(new EventHandler<ActionEvent>(){
            public void handle(ActionEvent ae)
            {
                label.setText("SUppp...vadvsdbfzdx hjbbd c");
            }
        });

        rootNode.getChildren().addAll(btn,label);
        myStage.show();
    }

}