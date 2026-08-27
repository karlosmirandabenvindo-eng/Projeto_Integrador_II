# PigTech CTBJ 
### *Sistema Escolar de Monitoramento e Manejo Inteligente da Pocilga do CTBJ*
> **Projeto de Automação e Bem-Estar Animal**  
> *Desenvolvido por alunos do Colégio Técnico de Bom Jesus (CTBJ/UFPI)*

---

##  Sobre o Projetinho (PigTech CTBJ)
O **PigTech CTBJ** nasceu da necessidade de modernizar a nossa rotina na pocilga do **Colégio Técnico de Bom Jesus**. Quem estuda aqui sabe que o calor de Bom Jesus não é brincadeira! Garantir o conforto térmico e a saúde dos porcos exige atenção constante. 

Para ajudar nossos técnicos no manejo diário e dar um suporte de alta tecnologia, criamos um sistema prático usando sensores baratinhos de **Internet das Coisas (IoT)** e automação simples. O foco é dar uma "mãozinha" pros técnicos, alertando quando a pocilga estiver quente demais ou quando o ar estiver abafado, permitindo que a gente cuide dos animais com mais precisão.

---

##  Contexto no Colégio Técnico de Bom Jesus
Este projeto une a vivência prática do campo com a tecnologia do ensino técnico:

*  **Apoio ao Manejo Técnico:** Nossos técnicos já realizam o manejo eventual e os cuidados diários obrigatórios. O sistema não substitui o trabalho deles, mas serve como um **"alarme inteligente"** para interrupções ou emergências (ex: pico de calor extremo).
*  **Integração de Cursos:** Une o conhecimento dos alunos de **Agropecuária** (bem-estar, manejo, nutrição) com **Informática/Eletrônica** (montagem de circuitos, programação de microcontroladores e envio de alertas).
*  **Protótipo de Baixo Custo:** Pensado para a realidade da nossa escola, utilizando placas acessíveis (como Arduino e ESP32) e sensores que podem ser mantidos pelos próprios estudantes.

---

##  Objetivos do PigTech
-  **Combater o Estresse Térmico:** Controlar os níveis de calor dentro da pocilga do CTBJ, acionando aspersores ou ventiladores automaticamente.
-  **Avisar o Técnico no Momento Certo:** Enviar mensagens de alerta para o celular do técnico responsável quando algum parâmetro fugir do ideal (como falta de água ou amônia alta).
-  **Gerar Dados de Pesquisa:** Registrar o histórico de temperatura e umidade da pocilga para ser usado em aulas práticas, relatórios e feiras de ciências da escola.
-  **Melhorar a Produtividade e Saúde:** Garantir que o ganho de peso dos porcos seja otimizado pela manutenção de um ambiente confortável.

---
##  Como Funciona o Sistema?
1. **Captura na Pocilga:** Instalamos sensores DHT22 (temperatura/umidade) e MQ-135 (gases) nos boxes dos porcos, além de boias eletrônicas nas caixas de água.
2. **Processamento:** O microcontrolador ESP32 recebe os dados via Wi-Fi da escola e checa se a temperatura passou dos limites aceitáveis para a fase de crescimento dos suínos.
3. **Ação Rápida:** 
   - Se estiver muito quente: aciona o relé do sistema de nebulização/ventilação da pocilga.
   - Se o gás amônia subir ou faltar água: envia uma notificação no grupo de WhatsApp/Telegram dos técnicos e monitores da pocilga.

---

##  Componentes Utilizados (Hardware e Software)

### Hardware
* **Microcontrolador:** ESP32 Wi-Fi / Bluetooth
* **Sensor de Temperatura e Umidade:** DHT22 (protegido contra umidade direta)
* **Sensor de Qualidade do Ar:** MQ-135 (detecção de amônia e gases)
* **Módulo Relé (4 Canais):** Para acionamento de bomba d'água e ventiladores
* **Sensor de Nível de Água:** Boia tipo chaveiro para bebedouros

### Software
* **C++ / Arduino IDE:** Código de programação embarcada do ESP32
* **Blynk / Telegram Bot API:** Interface visual no celular e envio de alertas em tempo real
* **Dashboard Local:** Painel simples em HTML/CSS hospedado na rede interna do CTBJ

---

##  Divisão de Tarefas na Escola

| Equipe / Perfil | Atribuição no Projeto |
| :--- | :--- |
| **Alunos de Agropecuária** | Definição das tabelas de conforto térmico, acompanhamento do peso dos porcos e inspeção diária. |
| **Alunos de Informática** | Programação da placa, configuração dos alertas via aplicativo e criação do painel visual. |
| **Técnicos da Pocilga** | Validação dos alertas na prática, apoio no manejo diário e supervisão das rotinas obrigatórias. |

---

##  Próximos Passos (Futuro do Projeto)
- [ ] Instalar microfones de baixo custo para identificar tosse frequente nos leitões.
- [ ] Criar um alimentador automatizado acionado por horário.
- [ ] Apresentar os resultados na Feira de Ciências e na Semana Acadêmica do CTBJ.

---
Colégio Técnico de Bom Jesus (CTBJ) - Ensino Prático e Inovação no Campo! 
