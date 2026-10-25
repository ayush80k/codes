import java.awt.*;
import java.awt.event.*;

public class CheckBoxDemo extends Frame implements ItemListener {
    Checkbox java, python, cpp, c;
    Label result;

    CheckBoxDemo() {
        setTitle("AWT CheckBox Demo");
        setLayout(new FlowLayout());
        add(new Label("Select your known languages:"));
        java = new Checkbox("Java");
        python = new Checkbox("Python");
        cpp = new Checkbox("C++");
        c = new Checkbox("C");
        result = new Label("Selected: none                                        ");
        for (Checkbox cb : new Checkbox[]{java, python, cpp, c}) {
            cb.addItemListener(this);
            add(cb);
        }
        add(result);
        setSize(350, 200);
        setVisible(true);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) { dispose(); System.exit(0); }
        });
    }

    public void itemStateChanged(ItemEvent e) {
        StringBuilder sb = new StringBuilder("Selected: ");
        if (java.getState()) sb.append("Java ");
        if (python.getState()) sb.append("Python ");
        if (cpp.getState()) sb.append("C++ ");
        if (c.getState()) sb.append("C ");
        result.setText(sb.toString());
    }

    public static void main(String[] args) { new CheckBoxDemo(); }
}
