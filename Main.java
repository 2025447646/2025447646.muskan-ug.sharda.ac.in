import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        while (true) {
            System.out.println("\n===== StudyMata AI =====");
            System.out.println("1. AI Doubt Solver");
            System.out.println("2. Notes Generator");
            System.out.println("3. Quiz");
            System.out.println("4. Study Planner");
            System.out.println("5. Exit");

            System.out.print("Enter Choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    doubtSolver();
                    break;

                case 2:
                    notesGenerator();
                    break;

                case 3:
                    quiz();
                    break;

                case 4:
                    studyPlanner();
                    break;

                case 5:
                    System.out.println("Thank You!");
                    System.exit(0);

                default:
                    System.out.println("Invalid Choice");
            }
        }
    }

    static void doubtSolver() {
        System.out.print("Enter your doubt: ");
        String doubt = sc.nextLine();

        System.out.println("\nAI Response:");
        System.out.println("Your doubt \"" + doubt + "\" has been received.");
        System.out.println("Please refer to your class notes and practice regularly.");
    }

    static void notesGenerator() {
        System.out.print("Enter Subject: ");
        String subject = sc.nextLine();

        System.out.println("\nGenerated Notes");
        System.out.println("----------------------");
        System.out.println("Subject : " + subject);
        System.out.println("• Read theory carefully.");
        System.out.println("• Practice important questions.");
        System.out.println("• Revise daily.");
    }

    static void quiz() {

        int score = 0;

        System.out.println("\nJava Quiz");

        System.out.println("Q1. Java is?");
        System.out.println("1. Programming Language");
        System.out.println("2. Browser");
        System.out.print("Answer: ");

        int ans = sc.nextInt();

        if (ans == 1)
            score++;

        System.out.println("Your Score = " + score + "/1");
    }

    static void studyPlanner() {

        sc.nextLine();

        System.out.print("Enter Subject: ");
        String subject = sc.nextLine();

        System.out.print("Study Hours: ");
        int hour = sc.nextInt();

        System.out.println("\nStudy Plan");
        System.out.println("----------------");
        System.out.println("Subject : " + subject);
        System.out.println("Hours : " + hour);
        System.out.println("Plan Created Successfully.");
    }
}