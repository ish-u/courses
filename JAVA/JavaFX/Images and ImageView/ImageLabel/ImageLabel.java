import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.image.*;
import javafx.scene.control.*;
import javafx.geometry.*;

public class ImageLabel extends Application
{
    public static void main(String args[])
    {
        launch(args);
    }

    //overring the start method of JavaFX Application class
    public void start(Stage myStage)
    {
        myStage.setTitle("IMAGE LABEL DEMO");
        FlowPane rootNode = new FlowPane();
        rootNode.setAlignment(Pos.CENTER);
        Scene myScene = new Scene(rootNode,700,700);
        myStage.setScene(myScene);

        ImageView hourglass = new ImageView("sky.jpg");
        Label label = new Label("SKY !;> ",hourglass);
        label.setContentDisplay(ContentDisplay.TOP);
        rootNode.getChildren().add(label);

        myStage.show();
    }
}