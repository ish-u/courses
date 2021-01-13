import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.geometry.*;
import javafx.scene.image.*;


public class ImageDemo extends Application
{
    public static void main(String args[])
    {
        launch(args);
    }

    //start() method of javafx application
    public void start(Stage myStage)
    {
        myStage.setTitle("IMAGE DEMO");
        FlowPane rootNode = new FlowPane();
        rootNode.setAlignment(Pos.CENTER);
        Scene myScene = new Scene(rootNode,400,500);
        myStage.setScene(myScene);

        //creating an Image Object
        Image sky = new Image("sky.jpg");
        //adding thr Image object to the ImageView Object b/c Image object is not derived from Node Class
        //(which is responsible for adding elemnets to the SceneGraph or Scene object (*-* idk)). Thus, we add Image
        //object to the ImageView Object beacuse it is derived from the Node Class.
        ImageView img = new ImageView(sky);

        //adding ImageView Object to the Scene Graph
        rootNode.getChildren().add(img);    

        myStage.show();

    }
}