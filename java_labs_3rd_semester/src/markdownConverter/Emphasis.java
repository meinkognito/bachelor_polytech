package markdownConverter;

import java.util.List;

public class Emphasis implements Markdown {

  private final List<Markdown> elements;

  Emphasis(List<Markdown> elements) {
    this.elements = elements;
  }

  Emphasis(Markdown element) {
    this.elements = List.of(element);
  }

  @Override
  public void toMarkdown(StringBuilder str) {
    str.append("*");

    for (Markdown element : elements) {
      element.toMarkdown(str);
    }

    str.append("*");
  }
}
