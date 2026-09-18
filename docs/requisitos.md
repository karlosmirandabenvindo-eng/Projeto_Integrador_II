# Documento de Requisitos (SRS) - PigTech CTBJ 
### *Sistema Escolar de Monitoramento e Manejo Inteligente da Pocilga do CTBJ*
> **Projeto de Automação e Bem-Estar Animal**  
> *Colégio Técnico de Bom Jesus (CTBJ/UFPI)*

---

## 1. Introdução

### 1.1 Objetivo
Este documento especifica os **Requisitos Funcionais (RF)** e **Requisitos Não Funcionais (RNF)** para o desenvolvimento do sistema **PigTech CTBJ**. O sistema visa auxiliar os técnicos agrícolas e alunos do Colégio Técnico de Bom Jesus na gestão e monitoramento do ambiente da pocilga da instituição.

### 1.2 Escopo do Projeto
O PigTech CTBJ abrange o sensoriamento ambiental de temperatura, umidade e emissão de gases (amônia), a verificação automática de nível de água nos bebedouros, o acionamento automatizado de sistemas de mitigação de calor (nebulização/ventilação) e o envio de alertas para os técnicos responsáveis.

---

## 2. Requisitos Funcionais (RF)

Os requisitos funcionais descrevem as ações, comandos e comportamentos esperados do sistema.

| Código | Nome do Requisito | Descrição Detalhada | Prioridade |
| :--- | :--- | :--- | :--- |
| **RF-01** | Coleta de Temperatura e Umidade | O sistema deve ler continuamente a temperatura ambiente e a umidade relativa do ar na pocilga através de sensores (ex: DHT22). | **Alta** |
| **RF-02** | Monitoramento de Amônia (MQ-135) | O sistema deve aferir a concentração do gás amônia no ar da pocilga para prevenir problemas respiratórios nos suínos. | **Média** |
| **RF-03** | Verificação de Nível de Água | O sistema deve verificar, por meio de sensores do tipo boia, se há fornecimento normal de água nos reservatórios/bebedouros. | **Alta** |
| **RF-04** | Acionamento Automático de Climatização | O sistema deve acionar relés para ligar nebulizadores ou ventiladores quando a temperatura ultrapassar o limite crítico de conforto térmico suíno. | **Alta** |
| **RF-05** | Envio de Alertas Emergenciais | O sistema deve enviar notificações automáticas via aplicativo (Telegram/WhatsApp/Blynk) aos técnicos e monitores em caso de inconsistência (ex: calor extremo, falta d'água). | **Alta** |
| **RF-06** | Exibição de Dashboard em Tempo Real | O sistema deve disponibilizar uma interface web/mobile simples para visualização dos dados atuais da pocilga na rede interna da escola. | **Média** |
| **RF-07** | Registro Histórico de Leituras | O sistema deve armazenar os dados de temperatura, umidade e acionamentos para fins de estudo e aulas práticas das turmas do CTBJ. | **Baixa** |
| **RF-08** | Intervenção Manual de Controle | O sistema deve permitir que os técnicos ou alunos autorizados ativem/desativem o sistema de ventilação manualmente através da interface. | **Média** |

---

## 3. Requisitos Não Funcionais (RNF)

Os requisitos não funcionais definem as qualidades, restrições e padrões técnicos que o sistema deve atender.

| Código | Nome do Requisito | Descrição Detalhada | Categoria |
| :--- | :--- | :--- | :--- |
| **RNF-01** | Baixo Custo de Implementação | Os componentes de hardware utilizados (ESP32, sensores, relés) devem ser de baixo custo e facilmente substituíveis no mercado local. | **Custo / Viabilidade** |
| **RNF-02** | Resistência ao Ambiente Granjeiro | Os sensores e o microcontrolador devem ficar dentro de caixas de proteção (grau de proteção IP65 ou caixa hermética) para suportar umidade, poeira e gases corrosivos. | **Confiabilidade / Hardware** |
| **RNF-03** | Tempo de Resposta de Alertas | As notificações de emergência (falta d'água ou superaquecimento) devem ser entregues aos técnicos em até **2 minutos** após a detecção. | **Desempenho** |
| **RNF-04** | Usabilidade Simplificada | A interface gráfica do Dashboard deve ser intuitiva, em português, permitindo a operação fácil por alunos de nível médio/técnico e funcionários. | **Usabilidade** |
| **RNF-05** | Funcionamento Off-line Básico | O acionamento local da ventilação deve continuar operando automaticamente com base nas regras pré-programadas, mesmo que haja queda na rede Wi-Fi do colégio. | **Disponibilidade** |
| **RNF-06** | Segurança de Tensão/Instalação | Os módulos de alta tensão (relés e bombas/ventiladores 110V/220V) devem possuir isolamento elétrico adequado para evitar riscos aos alunos e aos técnicos. | **Segurança** |
| **RNF-07** | Modularidade do Código | O código-fonte embarcado no ESP32 deve ser documentado e comentado em português para facilitar o aprendizado e melhorias por turmas futuras. | **Manutenibilidade** |

---

## 4. Matriz de Rastreabilidade / Papéis

| Requisito | Responsável Principal | Usuário Beneficiado |
| :--- | :--- | :--- |
| **RF-01, RF-02, RF-03** | Alunos de Informática / Eletrônica | Técnicos da Pocilga e Alunos de Agropecuária |
| **RF-04, RF-08** | Alunos de Informática / Eletrônica | Porcos / Técnicos da Pocilga |
| **RF-05** | Alunos de Informática | Técnicos de Manejo do CTBJ |
| **RF-06, RF-07** | Alunos de Informática e Agropecuária | Professores e Alunos em Aulas Práticas |

---
*Documento gerado para composição do repositório oficial do projeto **PigTech CTBJ**.*
