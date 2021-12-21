package markdownConverter;

import java.util.List;

public class Paragraph implements Markdown {

  private final List<Markdown> elements;

  Paragraph(List<Markdown> elements) {
    this.elements = elements;
  }

  Paragraph(Markdown element) {
    this.elements = List.of(element);
  }

  @Override
  public void toMarkdown(StringBuilder str) {
    for (Markdown element : elements) {
      element.toMarkdown(str);
    }
  }

}
