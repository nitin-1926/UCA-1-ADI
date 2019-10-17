import java.util.*;
import java.io.IOException;

class Tertis {

    ShapeTemplate m[];
    ShapeTemplate k;
    Board b;
    Random r;
    Stack<String> stack;

    Stack<String> redoStack;

    boolean status;

    Tertis() {
        m = new ShapeTemplate[] { new Line(), new T(), new Sq(), new Z(), new L() };

        k = m[(int) (Math.random() * 5)];
        b = new Board();

        stack = new Stack<String>();

        redoStack = new Stack<String>();

    }

    public static void main(String[] args) throws IOException, InterruptedException {
        // System.out.println("Kya mai chall ra hu");

        Tertis t = new Tertis();
        t.boardFunctions();
        Scanner sc = new Scanner(System.in);

        // new Timer().scheduleAtFixedRate(new TimerTask() {
        // @Override
        // public void run() {
        // t.k.moveDown();
        // t.boardFunctions();
        // }
        // }, 0, 500);
        // RunBackground rb = new RunBackground();
        // rb.send(t);
        // rb.start();
        char choice = sc.next().charAt(0);

        while (choice != 'e') {

            switch (choice) {
            case 's':
                t.redoStack = new Stack<String>();
                t.k.rotateLeft();
                t.stack.push("s");
                t.boardFunctions();
                break;

            case 'w':
                t.redoStack = new Stack<String>();
                t.k.rotateRight();
                t.stack.push("w");
                t.boardFunctions();
                break;

            case 'd':
                t.redoStack = new Stack<String>();
                t.status = t.k.moveRight(t.b);
                if (t.status) {
                    t.stack.push("d");
                }
                t.boardFunctions();
                break;

            case 'a':
                t.redoStack = new Stack<String>();
                t.status = t.k.moveLeft(t.b);
                if (t.status) {
                    t.stack.push("a");
                }
                t.boardFunctions();
                break;

            case 'x':
                t.redoStack = new Stack<String>();
                t.k.moveDown();
                t.stack.push("x");
                t.boardFunctions();
                break;

            case 'u':

                if (t.stack.empty()) {
                    t.boardFunctions();
                    // System.out.println("hi");
                } else {
                    // System.out.println("hi Undo Working");
                    if (t.stack.peek() == "s") {
                        t.redoStack.push(t.stack.pop());
                        t.k.rotateRight();
                    } else if (t.stack.peek() == "w") {
                        t.redoStack.push(t.stack.pop());
                        t.k.rotateLeft();
                    } else if (t.stack.peek() == "d") {
                        t.redoStack.push(t.stack.pop());
                        t.k.moveLeft(t.b);
                    } else if (t.stack.peek() == "a") {
                        t.redoStack.push(t.stack.pop());
                        t.k.moveRight(t.b);
                    } else {
                        t.redoStack.push(t.stack.pop());
                        t.k.moveUp();
                    }
                    t.boardFunctions();
                }
                break;
            case 'r':
                if (t.redoStack.empty()) {
                    t.boardFunctions();
                    // System.out.println("hi");
                } else {
                    // System.out.println("hi Redo Working");
                    if (t.redoStack.peek() == "s") {
                        t.stack.push(t.redoStack.pop());
                        t.k.rotateLeft();
                    } else if (t.redoStack.peek() == "w") {
                        t.stack.push(t.redoStack.pop());
                        t.k.rotateLeft();
                    } else if (t.redoStack.peek() == "d") {
                        t.stack.push(t.redoStack.pop());
                        t.k.moveRight(t.b);
                    } else if (t.redoStack.peek() == "a") {
                        t.stack.push(t.redoStack.pop());
                        t.k.moveLeft(t.b);
                    } else {
                        t.stack.push(t.redoStack.pop());
                        t.k.moveDown();
                    }
                    t.boardFunctions();
                }
                break;

            }
            choice = sc.next().charAt(0);
        }

        sc.close();

    }

    void boardFunctions() throws IOException, InterruptedException {
        b.makeBoard();
        boolean flag = b.insertShape(k.getCurrentShape());
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        b.printBoard();
        if (flag) {
            m = new ShapeTemplate[] { new Line(), new T(), new Sq(), new Z(), new L() };
            k = m[(int) (Math.random() * 5)];
            boardFunctions();
            stack = new Stack<String>();
            redoStack = new Stack<String>();

        }
    }

}

// class RunBackground extends Thread {

// Tertis t;

// public void run() {
// new Timer().scheduleAtFixedRate(new TimerTask() {
// @Override
// public void run() {
// try {
// System.out.println("i am runned at all");
// t.k.moveDown();
// t.boardFunctions();
// } catch (Exception e) {
// System.out.println("i am not able to run");
// }

// }
// }, 0, 500);
// }

// void send(Tertis th) {
// t = th;
// }
// }

class Board {

    public char board[][] = new char[30][31];
    public char finalBoard[][] = new char[30][31];

    Board() {
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                if (i == 0 || i == 29 || j == 0 || j == 29) {
                    finalBoard[i][j] = '*';
                } else
                    finalBoard[i][j] = ' ';
            }
        }
        for (int i = 0; i < 30; i++) {
            finalBoard[i][30] = '0';
        }
    }

    public void makeBoard() {
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                if (i == 0 || i == 29 || j == 0 || j == 29) {
                    board[i][j] = '*';
                } else
                    board[i][j] = ' ';
            }
        }
    }

    void save(int[][] co) {
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                if (board[i][j] == '#') {
                    finalBoard[i][j] = '$';
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            finalBoard[co[i][0] + 4][30]++;
        }
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 31; j++) {
                System.out.print(finalBoard[i][j] + " ");
            }
            System.out.println("");

        }
        for (int i = 0; i < 30; i++) {
            if (finalBoard[i][30] - '0' == 28) {
                for (int m = i; finalBoard[m][30] > '0'; m--) {
                    for (int n = 1; n < 29; n++) {
                        finalBoard[m][n] = finalBoard[m - 1][n];
                    }
                }
            }
        }

    }

    public boolean insertShape(Shape s) {
        int[][] co = s.getCordinates();
        // int max = s.getMax();
        boolean flag = false;
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                if (board[i][j] != '#')
                    board[i][j] = finalBoard[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            // System.out.println(max + 4 + " " + (co[i][0] + 4) + " " + (co[i][1] + 4));

            if ((board[(co[i][0] + 5)][co[i][1] + 4] == '$' || board[(co[i][0] + 5)][co[i][1] + 4] == '*')) {
                /// System.out.println("ye lo paji " + (max + 4) + " " + (co[i][0] + 4) + " " +
                /// (co[i][1] + 4));
                flag = true;

                // System.out.println("hii i am called at all");
            }
            board[(co[i][0] + 4)][co[i][1] + 4] = '#';
        }
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                if (board[i][j] == '$')
                    board[i][j] = '#';
            }
        }

        if (flag) {

            save(co);
        }
        return flag;

    }

    public void printBoard() {

        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println("");

        }
    }
}

class Shape {
    int[][] shape = new int[4][2];
    // int min, max, verMax;

    Shape(int[][] ar) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++) {
                shape[i][j] = ar[i][j];
            }
        }
        // calcMinMax();
    }

    int[][] getCordinates() {
        return shape;
    }

    // int getMax() {
    // return verMax;
    // }

    // void calcMinMax() {
    // min = 40;
    // max = -40;
    // verMax = -40;
    // for (int i = 0; i < 4; i++) {
    // if (max < shape[i][1]) {
    // max = shape[i][1];
    // }
    // }
    // for (int i = 0; i < 4; i++) {
    // if (min > shape[i][1]) {
    // min = shape[i][1];
    // }
    // }
    // for (int i = 0; i < 4; i++) {
    // // System.out.println(shape[i][0] + 4);

    // if (verMax < shape[i][0]) {
    // verMax = shape[i][0];
    // }
    // }
    // System.out.println("");
    // }

    boolean moveRight(Board b) {

        for (int i = 0; i < 4; i++) {
            if (b.finalBoard[shape[i][0] + 4][shape[i][1] + 5] == '$'
                    || b.finalBoard[shape[i][0] + 4][shape[i][1] + 5] == '*') {

                // System.out.println("printing Final Board start");
                // for (int m = 0; m < 30; m++) {
                // for (int j = 0; j < 30; j++) {
                // System.out.print(b.finalBoard[m][j]);
                // }
                // System.out.println("");
                // }
                // System.out.println("printing Final Board end");
                System.out.println(b.finalBoard[shape[i][0] + 4][shape[i][1] + 5] == '*');
                return false;
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < 2; j++) {
                shape[i][j] += 1;
            }
        }
        // max++;
        return true;
    }

    boolean moveLeft(Board b) {
        // calcMinMax();

        for (int i = 0; i < 4; i++) {
            if (b.finalBoard[shape[i][0] + 4][shape[i][1] + 3] == '$'
                    || b.finalBoard[shape[i][0] + 4][shape[i][1] + 3] == '*') {
                return false;
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < 2; j++) {
                shape[i][j] -= 1;
            }
        }
        // min--;
        return true;
    }

    void moveDown() {

        // calcMinMax();
        // if ((verMax + 5) > 28) {
        // return false;
        // }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 1; j++) {
                shape[i][j] += 1;
            }
        }
        // verMax++;
        // return true;
    }

    void moveUp() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 1; j++) {
                shape[i][j] -= 1;
            }
        }

    }
}

class ShapeTemplate {
    Shape main;
    Shape left;
    Shape right;
    Shape invert;
    int current = 0;

    Shape[] states;

    public Shape getCurrentShape() {
        return states[current];
    }

    public void rotateLeft() {
        if (current < 4 && current != 0) {
            current -= 1;
        } else if (current == 0) {
            current = 3;
        }
    }

    public void rotateRight() {
        if (current < 3) {
            current += 1;
        } else if (current == 3) {
            current = 0;
        }
    }

    boolean moveRight(Board b) {
        for (int i = 0; i < 4; i++) {
            if (!states[i].moveRight(b)) {
                return false;
            }
        }
        return true;
    }

    boolean moveLeft(Board b) {
        for (int i = 0; i < 4; i++) {
            if (!states[i].moveLeft(b)) {
                return false;
            }
        }
        return true;
    }

    void moveDown() {
        for (int i = 0; i < 4; i++) {
            states[i].moveDown();
        }
    }

    void moveUp() {
        for (int i = 0; i < 4; i++) {
            states[i].moveUp();
        }
    }

}

class Line extends ShapeTemplate {

    Line() {
        current = 0;
        main = new Shape(new int[][] { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } });
        left = new Shape(new int[][] { { 0, 0 }, { 0, -1 }, { 0, -2 }, { 0, -3 } });
        right = new Shape(new int[][] { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } });
        invert = new Shape(new int[][] { { 0, 0 }, { -1, 0 }, { -2, 0 }, { -3, 0 } });
        states = new Shape[] { main, right, invert, left };
    }

}

class T extends ShapeTemplate {

    T() {
        current = 0;
        main = new Shape(new int[][] { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } });
        left = new Shape(new int[][] { { 0, 0 }, { 0, 1 }, { -1, 0 }, { 1, 0 } });
        right = new Shape(new int[][] { { 0, 0 }, { -1, 0 }, { 1, 0 }, { 0, -1 } });
        invert = new Shape(new int[][] { { 0, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } });
        states = new Shape[] { main, right, invert, left };
    }

}

class L extends ShapeTemplate {
    L() {
        current = 0;
        main = new Shape(new int[][] { { 0, 0 }, { 0, 1 }, { -1, 0 }, { -2, 0 } });
        left = new Shape(new int[][] { { 0, 0 }, { -1, 0 }, { 0, -2 }, { 0, -1 } });
        right = new Shape(new int[][] { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 } });
        invert = new Shape(new int[][] { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 0, -1 } });
        states = new Shape[] { main, right, invert, left };
    }
}

class Z extends ShapeTemplate {
    Z() {
        current = 0;
        main = new Shape(new int[][] { { 0, 0 }, { -1, -1 }, { 0, -1 }, { 1, 0 } });
        // Shape left = new Shape(new int[][] { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, -1 }
        // });
        right = new Shape(new int[][] { { 0, 0 }, { -1, 0 }, { -1, 1 }, { 0, -1 } });
        // Shape invert = new Shape(new int[][]{
        // {0,0},{}
        // });
        states = new Shape[] { main, right };
    }

    public void rotateLeft() {
        if (current < 2 && current != 0) {
            current -= 1;
        } else if (current == 0) {
            current = 1;
        }
    }

    public void rotateRight() {
        if (current < 1) {
            current += 1;
        } else if (current == 1) {
            current = 0;
        }
    }

    boolean moveRight(Board b) {
        for (int i = 0; i < 2; i++) {
            if (!states[i].moveRight(b)) {
                return false;
            }
        }
        return true;
    }

    boolean moveLeft(Board b) {
        for (int i = 0; i < 2; i++) {
            if (!states[i].moveLeft(b)) {
                return false;
            }
        }
        return true;
    }

    void moveDown() {
        for (int i = 0; i < 2; i++) {
            states[i].moveDown();
        }
    }
}

class Sq extends ShapeTemplate {

    Sq() {
        current = 0;
        main = new Shape(new int[][] { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } });
        left = new Shape(new int[][] { { 0, 0 }, { 0, -1 }, { 0, -2 }, { 0, -3 } });
        right = new Shape(new int[][] { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } });
        invert = new Shape(new int[][] { { 0, 0 }, { -1, 0 }, { -2, 0 }, { -3, 0 } });
        states = new Shape[] { main, right, invert, left };
    }

}