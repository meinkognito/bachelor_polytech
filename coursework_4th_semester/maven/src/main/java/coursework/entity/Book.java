package coursework.entity;

import javax.persistence.*;
import lombok.NoArgsConstructor;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Entity
@Table(name = "BOOKS")
@NoArgsConstructor
public class Book {

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Column(name = "name", nullable = false, length = 50)
  private String name;

  @Column(name = "cnt", nullable = false)
  private Integer count;

  @ManyToOne
  @JoinColumn(
      name = "type_id",
      foreignKey = @ForeignKey(
          name = "fk_books_book_types"
      )
  )
  private BookType type;

  public Book(String name, Integer count, BookType type) {
    this.name = name;
    this.count = count;
    this.type = type;
  }
}
