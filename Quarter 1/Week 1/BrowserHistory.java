import java.util.ArrayList;
import java.util.List;

public class BrowserHistory {
    int currentPage;
    List<String> history;

    public BrowserHistory(String homepage) {
        currentPage = 0;
        history = new ArrayList<>();
        history.add(homepage);
    }

    public void visit(String url) {
        if(currentPage < history.size() - 1) {
            history = history.subList(0, currentPage);
            currentPage = history.size() - 1;
        }
        history.add(url);
        currentPage++;
    }

    public String back(int steps) {
        for(int i = 0; i < steps; i++) {
            if(currentPage == 0) {
                return history.get(0);
            } else {
                currentPage--;
            }
        }

        return history.get(currentPage);
    }

    public String forward(int steps) {
        for(int i = 0; i < steps; i++) {
            if(currentPage == history.size()-1) {
                return history.get(history.size() - 1);
            } else {
                currentPage++;
            }
        }
        return history.get(currentPage);
    }

    public static void main(String[] args) {
        BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
        browserHistory.visit("google.com");
        browserHistory.visit("facebook.com");
        browserHistory.visit("youtube.com");
        browserHistory.back(1);
        browserHistory.back(1);
        browserHistory.forward(1);
        browserHistory.visit("linkedin.com");
        browserHistory.forward(2);
        browserHistory.back(2);
        browserHistory.back(7);
    }
}