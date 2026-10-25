import java.io.Serializable;

/** A JavaBean: public no-arg constructor, private properties, getters/setters, Serializable. */
public class StudentBean implements Serializable {
    private static final long serialVersionUID = 1L;
    private int rollNo;
    private String name;
    private double marks;

    public StudentBean() { }

    public int getRollNo() { return rollNo; }
    public void setRollNo(int rollNo) { this.rollNo = rollNo; }
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    public double getMarks() { return marks; }
    public void setMarks(double marks) { this.marks = marks; }
}
