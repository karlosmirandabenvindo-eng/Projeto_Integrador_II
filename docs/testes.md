# Relatório de Validação e Testes - PigTech CTBJ 
> **Disciplina:** Projeto Integrador II  
> **Local de Teste:** Pocilga do Colégio Técnico de Bom Jesus (CTBJ/UFPI)

---

## 1. Testes de Unidade e Integração (Hardware / Software)

| ID | Caso de Teste | Procedimento | Resultado Esperado | Resultado Obtido | Status |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **TC-01** | Leitura de Temperatura | Submeter o DHT22 a variação térmica controlada no laboratório. | Variação rápida nos dados sem travamento. | Sensor leu de 24°C a 34°C com precisão de ±0.5°C. | 🟢 Aprovado |
| **TC-02** | Disparo do Relé de Nebulização | Simular temperatura de 29°C no código. | O relé deve fechar contato em até 2 segundos. | Relé acionou em 0.8s, acendendo o sistema de ventiladores. | 🟢 Aprovado |
| **TC-03** | Envio de Alertas Telegram | Desconectar a boia d'água para simular bebedouro vazio. | Envio de mensagem no Telegram do técnico em < 2 min. | Mensagem recebida em 12 segundos via Wi-Fi do colégio. | 🟢 Aprovado |

---

## 2. Teste de Usabilidade e Validação Prática

* **Avaliador:** Técnico Gabriel (Manejo de Suínos do CTBJ)
* **Ambiente:** Pocilga do CTBJ - Baia de Terminação
* **Feedback Coletado:**
  > *"O sistema ajudou demais nos horários de pico de calor em Bom Jesus (entre 12h e 15h). O alerta no celular facilita bastante para ir checar a água antes do lote sentir sede."*

---

## 3. Matriz de Cobertura de Requisitos

* **Requisitos Funcionais Testados:** RF-01, RF-02, RF-03, RF-04, RF-05, RF-06 e RF-08 (100% validados).
* **Conclusão:** O protótipo atendeu aos critérios operacionais de baixo custo e usabilidade estabelecidos para o colégio.
