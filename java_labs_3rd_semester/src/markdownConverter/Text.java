package markdownConverter;

public class Text implements Markdown {

  private final String text;

  Text(String text) {
    this.text = text;
  }

  @Override
  public void toMarkdown(StringBuilder str) {
    str.append(text);
  }
}
