package coursework.service;

import coursework.entity.Client;
import coursework.repositories.ClientsRepostitory;
import java.util.List;
import java.util.NoSuchElementException;
import javax.transaction.Transactional;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

@Service
@AllArgsConstructor
public class ClientsService {

  private final ClientsRepostitory clientsRepostitory;

  public List<Client> listOfClients() {
    return clientsRepostitory.findAll();
  }

  public Client getClientById(Long id) throws NoSuchElementException {
    return clientsRepostitory.findById(id)
        .orElseThrow(() -> new NoSuchElementException("no client"));
  }

  public Client addClient(Client newClient) {
    return clientsRepostitory.save(newClient);
  }

  public List<Client> addClients(List<Client> clients) {
    return clientsRepostitory.saveAll(clients);
  }

  @Transactional
  public Client updateClient(Long id, Client client) throws NoSuchElementException {
    Client draft = clientsRepostitory.findById(id)
        .orElseThrow(() -> new NoSuchElementException("no client"));

    draft.setFirstName(client.getFirstName());
    draft.setLastName(client.getLastName());
    draft.setPatherName(client.getPatherName());
    draft.setPassportSeria(client.getPassportSeria());
    draft.setPassportNumber(client.getPassportNumber());
    return draft;
  }

  public Client deleteClient(Long id) throws NoSuchElementException {
    Client clientToDelete = clientsRepostitory.findById(id)
        .orElseThrow(() -> new NoSuchElementException("no client"));

    clientsRepostitory.delete(clientToDelete);
    return clientToDelete;
  }
}
