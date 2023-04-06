import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Open files for reading
        Scanner all_ids_file;
        Scanner garbage_ids_file;
        try {
            all_ids_file = new Scanner(new File("EcoAll.txt"));
            garbage_ids_file = new Scanner(new File("Echogarbage.txt"));
        } catch (FileNotFoundException e) {
            System.out.println("Error: Unable to open file.");
            return;
        }

        // Read all IDs from all_ids.txt into a list
        List<String> all_ids = new ArrayList<String>();
        while (all_ids_file.hasNextLine()) {
            String id = all_ids_file.nextLine();
            all_ids.add(id);
        }
        all_ids_file.close();

        // Read all IDs from garbage_ids.txt into a list
        List<String> garbage_ids = new ArrayList<String>();
        while (garbage_ids_file.hasNext()) {
            String id = garbage_ids_file.next();
            // Check if the ID is 9 digits long
            if (id.length() == 9 && id.matches("[0-9]+")) {
                garbage_ids.add(id);
            }
        }
        garbage_ids_file.close();

        // Find the missing IDs
        List<String> missing_ids = new ArrayList<String>();
        for (String student_id : all_ids) {
            if (!garbage_ids.contains(student_id)) {
                missing_ids.add(student_id);
            }
        }

        // Print the missing IDs
        System.out.println("Absent students:");
        int a = 0;
        for (String student_id : missing_ids) {
            System.out.println(++a + " " + student_id);
        }
    }
}
