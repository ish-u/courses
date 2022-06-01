#include <iostream>
#include <graphics.h>
using namespace std;

// Sutherland-Hodgeman Polygon Clipping Algorithm
// Taken from  - Computer Graphics Principles and Practice in C - Foley
const int MAX = 100;
struct point
{
    double x;
    double y;
};

typedef point vertex;
typedef vertex edge[2];
typedef vertex vertexArray[MAX];

// Clip Region
const vertex maxClipPoint = {600, 450};
const vertex minClipPoint = {50, 50};
// Clip Edges
const edge RIGHT = {{maxClipPoint.x, minClipPoint.y}, {maxClipPoint.x, maxClipPoint.y}};
const edge TOP = {{maxClipPoint.x, maxClipPoint.y}, {minClipPoint.x, maxClipPoint.y}};
const edge LEFT = {{minClipPoint.x, maxClipPoint.y}, {minClipPoint.x, minClipPoint.y}};
const edge BOTTOM{{minClipPoint.x, minClipPoint.y}, {maxClipPoint.x, minClipPoint.y}};

static void Output(vertex, int *, vertexArray);
static boolean Inside(vertex, edge);
static vertex Intersect(vertex, vertex, edge);

static void Output(vertex newVertex, int *outLength, vertexArray outVertexArray)
{
    // cout << *outLength;
    if (*outLength < MAX)
    {
        outVertexArray[(*outLength)++] = newVertex;
    }
}

static boolean Inside(vertex testVertex, const edge clipBoundary)
{
    int position = ((clipBoundary[1].x - clipBoundary[0].x) * (testVertex.y - clipBoundary[0].y)) - ((clipBoundary[1].y - clipBoundary[0].y) * (testVertex.x - clipBoundary[0].x));
    return position > 0 ? TRUE : FALSE;
}

static vertex Intersect(vertex first, vertex second, const edge clipBoundary)
{
    vertex intersect;
    intersect.x = ((first.x * second.y - first.y * second.x) * (clipBoundary[0].x - clipBoundary[1].x) - (first.x - second.x) * (clipBoundary[0].x * clipBoundary[1].y - clipBoundary[0].y * clipBoundary[1].x)) / ((first.x - second.x) * (clipBoundary[0].y - clipBoundary[1].y) - (first.y - second.y) * (clipBoundary[0].x - clipBoundary[1].x));
    intersect.y = ((first.x * second.y - first.y * second.x) * (clipBoundary[0].y - clipBoundary[1].y) - (first.y - second.y) * (clipBoundary[0].x * clipBoundary[1].y - clipBoundary[0].y * clipBoundary[1].x)) / ((first.x - second.x) * (clipBoundary[0].y - clipBoundary[1].y) - (first.y - second.y) * (clipBoundary[0].x - clipBoundary[1].x));
    // cout << intersect.x << "\t" << intersect.y << "\n";
    return intersect;
}

void SutherlandHodgmanPolygonClip(vertexArray inVertexArray, vertexArray outVertexArray, int *inLength, int *outLength, const edge clipBoundary)
{
    /*
                     s - p
        Case 1 - Inside-Inside
        Case 2 - Inside-Outside
        Case 3 - Outside-Outside
        Case 4 - Outside-Inside
    */

    vertex s, p, i;
    *outLength = 0;

    // starting with the Last Vertex
    s = inVertexArray[(*inLength) - 1];
    for (int j = 0; j < *inLength; j++)
    {
        p = inVertexArray[j];
        // Case 1 and 4
        if (Inside(p, clipBoundary))
        {
            // Case 1
            if (Inside(s, clipBoundary))
            {
                Output(p, outLength, outVertexArray);
            }
            // Case 4
            else
            {
                i = Intersect(s, p, clipBoundary);
                Output(i, outLength, outVertexArray);
                Output(p, outLength, outVertexArray);
            }
        }
        // Case 2 and 3
        else
        {
            // Case 2
            if (Inside(s, clipBoundary))
            {
                i = Intersect(s, p, clipBoundary);
                Output(i, outLength, outVertexArray);
            }
            // No action is to be performed for case 3
        }
        s = p;
    }

    // Copying the inVertexArray with outVertexArray
    if (*outLength > 0)
    {
        *inLength = *outLength;
        // cout << "Length " << *outLength << "\n";
        for (int i = 0; i < *outLength; i++)
        {
            inVertexArray[i] = outVertexArray[i];
            // cout << outVertexArray[i].x << " ," << outVertexArray[i].y << "\t";
        }
    }
    // cout << "\n";
}

// Drawing the Clipped Rectangle
static void drawClipRectangle()
{
    line(TOP[0].x, -1 * TOP[0].y + getmaxy(), TOP[1].x, -1 * TOP[1].y + getmaxy());
    line(RIGHT[0].x, -1 * RIGHT[0].y + getmaxy(), RIGHT[1].x, -1 * RIGHT[1].y + getmaxy());
    line(BOTTOM[0].x, -1 * BOTTOM[0].y + getmaxy(), BOTTOM[1].x, -1 * BOTTOM[1].y + getmaxy());
    line(LEFT[0].x, -1 * LEFT[0].y + getmaxy(), LEFT[1].x, -1 * LEFT[1].y + getmaxy());
}

static void drawClippedPolygon(vertexArray inVertexArray, int inLength)
{

    // Clipped Polygon
    int outLength = 0;
    vertexArray outVertexArray;

    // Clipping the Polygon -  R->T->L->B
    SutherlandHodgmanPolygonClip(inVertexArray, outVertexArray, &inLength, &outLength, RIGHT);
    SutherlandHodgmanPolygonClip(inVertexArray, outVertexArray, &inLength, &outLength, TOP);
    SutherlandHodgmanPolygonClip(inVertexArray, outVertexArray, &inLength, &outLength, LEFT);
    SutherlandHodgmanPolygonClip(inVertexArray, outVertexArray, &inLength, &outLength, BOTTOM);

    // Drawing the clipped Polygon
    drawClipRectangle();
    vertex s, p;
    s = inVertexArray[(inLength)-1];
    for (int j = 0; j < inLength; j++)
    {
        p = inVertexArray[j];
        line(s.x, -1 * s.y + getmaxy(), p.x, -1 * p.y + getmaxy());
        s = p;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Polygoon to Clip
    int inLength = 6;
    vertexArray inVertexArray = {{100, 150}, {200, 250}, {300, 200}, {620, 400}, {450, 30}};

    // Drawing the Uncliped Polygon
    vertex s, p;
    char textBefore[50] = "Before Clipping";
    outtextxy(getmaxx() / 2 - 50, 5, textBefore);
    drawClipRectangle();
    s = inVertexArray[(inLength)-1];
    for (int j = 0; j < inLength; j++)
    {
        p = inVertexArray[j];
        line(s.x, -1 * s.y + getmaxy(), p.x, -1 * p.y + getmaxy());
        s = p;
    }

    system("pause");
    cleardevice();

    // Drawing the Clipped Polygon
    char textAfter[50] = "After Clipping";
    outtextxy(getmaxx() / 2 - 50, 5, textAfter);
    drawClippedPolygon(inVertexArray, inLength);

    system("pause");
    closegraph();

    return 0;
}
