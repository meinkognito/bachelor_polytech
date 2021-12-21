package markdownConverter;

import java.util.List;

public class Strikeout implements Markdown {

  private final List<Markdown> elements;

  Strikeout(List<Markdown> elements) {
    this.elements = elements;
  }

  Strikeout(Markdown element) {
    this.elements = List.of(element);
  }

  @Override
  public void toMarkdown(StringBuilder str) {
    str.append("~");

    for (Markdown element : elements) {
      element.toMarkdown(str);
    }

    str.append("~");
  }
}
