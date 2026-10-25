import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SwingComponents extends JFrame implements ActionListener {
    JTextField nameField;
    JRadioButton male, female;
    JCheckBox c1, c2;
    JComboBox<String> city;
    JTextArea output;
    JButton submit;

    SwingComponents() {
        setTitle("Swing Components Demo");
        setLayout(new FlowLayout());
        add(new JLabel("Name:"));
        nameField = new JTextField(15);
        add(nameField);

        male = new JRadioButton("Male");
        female = new JRadioButton("Female");
        ButtonGroup bg = new ButtonGroup();
        bg.add(male); bg.add(female);
        add(male); add(female);

        c1 = new JCheckBox("Java");
        c2 = new JCheckBox("Python");
        add(c1); add(c2);

        city = new JComboBox<>(new String[]{"Mumbai", "Pune", "Delhi", "Nagpur"});
        add(city);

        submit = new JButton("Submit");
        submit.addActionListener(this);
        add(submit);

        output = new JTextArea(6, 28);
        output.setEditable(false);
        add(new JScrollPane(output));

        setSize(360, 330);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String gender = male.isSelected() ? "Male" : female.isSelected() ? "Female" : "Not selected";
        String skills = (c1.isSelected() ? "Java " : "") + (c2.isSelected() ? "Python" : "");
        output.setText("Name: " + nameField.getText() + "\nGender: " + gender
                + "\nSkills: " + skills + "\nCity: " + city.getSelectedItem());
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(SwingComponents::new);
    }
}
