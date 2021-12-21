package markdownConverter;

import java.util.List;

public class Strong implements Markdown {

  private final List<Markdown> elements;

  Strong(List<Markdown> elements) {
    this.elements = elements;
  }

  Strong(Markdown element) {
    this.elements = List.of(element);
  }

  @Override
  public void toMarkdown(StringBuilder str) {
    str.append("__");

    for (Markdown element : elements) {
      element.toMarkdown(str);
    }

    str.append("__");
  }
}
