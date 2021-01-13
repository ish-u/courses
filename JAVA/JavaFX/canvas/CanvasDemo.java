import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;
import javafx.scene.shape.*;
import javafx.scene.canvas.*;
import javafx.scene.paint.*;
import javafx.scene.text.*;

public class CanvasDemo extends Application{

    public static void main(String args[])
    {
        //to launch the javaFX Application
        launch(args);
    }

    GraphicsContext gc;
    Color[] colors = {Color.RED, Color.BLUE, Color.GREEN, Color.BLACK};
    int colorIdx = 0;

    //overriding the start mehtod defined by he Application class that we inherited in this class
    public void start(Stage myStage)
    {
        myStage.setTitle("LET's DRAW");
        FlowPane rootNode = new FlowPane();
        rootNode.setAlignment(Pos.CENTER);
        Scene myScene = new Scene(rootNode, 500 ,500);
        myStage.setScene(myScene);

        //creating Canvas
        Canvas canvas = new Canvas(400, 400);
        //getting the GraphicsContext object for the created Canvas Object to use respective functions of this object to draw on the Canvas
        gc = canvas.getGraphicsContext2D();
        
        Button btn = new Button("Change Color");

        //to change color on pressing the button
        btn.setOnAction(new EventHandler<ActionEvent>(){
            public void handle(ActionEvent ae)
            {
                //setting the fill and stroke color
                gc.setStroke(colors[colorIdx]);
                gc.setFill(colors[colorIdx]);

                //redrawing the lines and shapes after changing the colors
                gc.strokeLine(0,0,200,200);
                gc.fillText("SUp..?!!",50,300);
                gc.fillRect(100,350,300,40);

                //changing the color
                colorIdx++;
                if(colorIdx == colors.length)
                {
                    colorIdx = 0;
                }
            }
        });

        gc.setFont(new Font(20));
        gc.strokeLine(0,0,200,200);
        gc.fillText("SUp..?!!",50,300);
        gc.fillRect(100,350,300,40);

        //adding the canvas and button to the scene
        rootNode.getChildren().addAll(canvas, btn);

        //showing the stage
        myStage.show();

    }
}