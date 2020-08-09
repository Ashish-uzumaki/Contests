import java.util.ArrayList;
import java.util.Comparator;
public class Test1 {
    public static void main(String[] args) {
    ArrayList<ClosedRegion> regions = new ArrayList<>();
    Circle c1 = new Circle(3.0, 4.0, 5.0);
    Circle c2 = new Circle(7.0, 1.0, 4.0);
    Rectangle r1 = new Rectangle(1.0, 1.0, 10.0, 4.0);
    Rectangle r2 = new Rectangle(4.0, 4.0, 2.0, 6.0);

// print out the center of c1 and r1; See Sample Output
// <implement>
    double [] cent = c1.getCenter();
    System.out.println(cent[0] + " " + cent[1]);
//
    regions.add(c1);
    regions.add(c2);
    regions.add(r1);
    regions.add(r2);
// implement a comparator AreaComparator defined below,
// that can be used to sort based on area of closed regions
    regions.sort(new AreaComparator());
// print out the area of each of the regions truncated to an integer
// as in in the sample output
// <implement>
    for(ClosedRegion area: AreaComparator){
        int ar = area.getArea();
        System.out.println(ar);
    }
    }
}
abstract class RegularShape {
    abstract double[] getCenter(); // a point which can be considered as the "center" of the shape
    // For a circle, its center
    // for a rectangle, the intersection of is diagonals
    // for a straight line, its mid point etc
}
interface ClosedRegion {
    double getArea(); // the area of the closed region.
}
class AreaComparator implements Comparator<ClosedRegion> {
    public int compare(ClosedRegion arg0, ClosedRegion arg1) {
    // <implement>
        if(arg0.getArea() <= arg1.getArea()){
            return 1;
        }
        return 0;
    }
}
class Circle … {
// is-a RegularShape and is-a ClosedRegion
    double[] cen = new int[5];
    double rad; 
    Circle(double cx, double cy, double radius) { // cx, cy are the coordinates of the center
    // <implement>
        cen[0] = cx;
        cen[1] = cy;
        rad = radius;
    }
// other inherited methods and/or data members
// <implement>
    double [] getCenter(){
        return cen;
    }

    double getArea(){
        return 3.14* rad* rad;
    }
}
class Rectangle ... {
// is-a RegularShape and is-a ClosedRegion
    double[] cen = new int[5];
    double length, width; 
    Rectangle(double x0, double y0, double length, double width) {
    // <implement>
    }
    // other inherited methods and/or data members
// <implement>
    double [] getCenter(){
        return cen;
    }

    double getArea(){
        return length*width;
    }
}