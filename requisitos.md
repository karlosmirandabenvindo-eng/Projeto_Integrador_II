## ⚙️ Como Funciona o Sistema?
---
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
*Colégio Técnico de Bom Jesus (CTBJ) - Ensino Prático e Inovação no Campo! *
