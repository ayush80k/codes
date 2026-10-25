public class TestBean {
    public static void main(String[] args) {
        StudentBean s = new StudentBean();
        s.setRollNo(101);
        s.setName("Riya");
        s.setMarks(88.5);
        System.out.println("Roll No: " + s.getRollNo());
        System.out.println("Name   : " + s.getName());
        System.out.println("Marks  : " + s.getMarks());
    }
}
