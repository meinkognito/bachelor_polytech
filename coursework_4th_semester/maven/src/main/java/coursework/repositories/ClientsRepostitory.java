package coursework.repositories;

import coursework.entity.Client;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ClientsRepostitory extends JpaRepository<Client, Long> {

}
