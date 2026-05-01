-- TESTE*
-- Catalógo inicial de exercícios (irei fazer ajustes, estou finalizando a pesquisa)
-- ================================================


-- ================================================
-- FASE MENSTRUAL
-- Energia baixa, hormônios em queda
-- Foco: alívio, recuperação, movimento suave
-- ================================================

-- MENSTRUAL | BEM_ESTAR | LEVE | sem restrição
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Balasana (Pose da Criança)',    '10 min', 'leve', 'bem_estar', 'menstrual', 'Joelhos abertos, testa no chão. Alivia cólicas e tensão lombar.', 'joelho'),
('Cat-Cow',                       '10 min', 'leve', 'bem_estar', 'menstrual', 'Alterna arqueamento e arredondamento da coluna. Mobiliza a pelve.', 'nenhuma'),
('Supta Baddha Konasana',         '10 min', 'leve', 'bem_estar', 'menstrual', 'Borboleta reclinada. Abre o quadril e relaxa o soalho pélvico.', 'nenhuma'),
('Savasana + Yoga Nidra',         '20 min', 'leve', 'bem_estar', 'menstrual', 'Relaxamento total. Reduz cortisol e melhora qualidade do sono.', 'nenhuma'),
('Torção Supina',                 '10 min', 'leve', 'bem_estar', 'menstrual', 'Deitada, joelhos caem para o lado. Alivia tensão espinhal.', 'lombar'),
('Nadi Shodhana (Pranayama)',     '15 min', 'leve', 'bem_estar', 'menstrual', 'Respiração alternada pelas narinas. Reduz cólicas e ansiedade.', 'nenhuma'),
('Matsyasana (Pose do Peixe)',    '10 min', 'leve', 'bem_estar', 'menstrual', 'Arco suave no peito. Abre tórax e estimula respiração profunda.', 'nenhuma');

-- MENSTRUAL | FORTALECIMENTO | LEVE | sem restrição
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Pelvic Tilt',                   '20 min', 'leve', 'fortalecimento', 'menstrual', 'Inclinação pélvica deitada. Ativa transverso sem impacto.', 'nenhuma'),
('Leg Slides',                    '20 min', 'leve', 'fortalecimento', 'menstrual', 'Deslizamento de pernas deitada. Core profundo sem esforço.', 'nenhuma'),
('Caminhada leve 20 min',         '20 min', 'leve', 'fortalecimento', 'menstrual', 'Ritmo de conversa. Libera endorfinas sem sobrecarregar.', 'tornozelo'),
('Natação suave',                 '25 min', 'leve', 'fortalecimento', 'menstrual', 'Nado livre lento. Pressão da água alivia inflamação pélvica.', 'nenhuma'),
('Foam roller lombar e quadril',  '15 min', 'leve', 'fortalecimento', 'menstrual', 'Liberação miofascial. Alivia tensão referida da dor uterina.', 'nenhuma');

-- MENSTRUAL | BEM_ESTAR | MODERADO
-- (para quem tem disposição média mesmo na menstruação)
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Pilates suave',                 '30 min', 'moderado', 'bem_estar', 'menstrual', 'Sequência de mat Pilates leve. Fortalece core sem impacto.', 'nenhuma'),
('Caminhada 30 min',              '30 min', 'moderado', 'bem_estar', 'menstrual', 'Caminhada mais longa em ritmo confortável.', 'tornozelo');


-- ================================================
-- FASE FOLICULAR
-- Energia crescente, estrogênio subindo
-- Foco: construção de força e resistência
-- ================================================

-- FOLICULAR | FORTALECIMENTO | LEVE
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Agachamento com peso corporal', '25 min', 'leve', 'fortalecimento', 'folicular', 'Sem carga. Ativa quadríceps e glúteos. Bom ponto de entrada.', 'joelho'),
('Flexão de braço modificada',    '20 min', 'leve', 'fortalecimento', 'folicular', 'Joelhos no chão. Peitoral e tríceps com baixo impacto.', 'ombro'),
('Prancha no antebraço',          '20 min', 'leve', 'fortalecimento', 'folicular', 'Core e estabilidade sem carga axial.', 'ombro'),
('Glute Bridge',                  '25 min', 'leve', 'fortalecimento', 'folicular', 'Ponte no chão sem barra. Glúteos e isquiotibiais.', 'nenhuma');

-- FOLICULAR | FORTALECIMENTO | MODERADO
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Lunges com halteres',           '35 min', 'moderado', 'fortalecimento', 'folicular', 'Avanço bilateral. Quadríceps, glúteo médio e equilíbrio.', 'joelho,tornozelo'),
('Supino com halteres',           '35 min', 'moderado', 'fortalecimento', 'folicular', 'Banco plano. Peitoral e tríceps com carga moderada.', 'ombro'),
('Remada curvada',                '35 min', 'moderado', 'fortalecimento', 'folicular', 'Barra ou halteres. Costas e bíceps.', 'lombar'),
('Corrida intervalada (Fartlek)', '35 min', 'moderado', 'fortalecimento', 'folicular', 'Alterna corrida rápida e trote. Melhora VO2max.', 'joelho,tornozelo');

-- FOLICULAR | FORTALECIMENTO | ALTA
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Agachamento livre (Back Squat)','45 min', 'alta', 'fortalecimento', 'folicular', 'Barra nas costas. Ideal para progressão de carga nessa fase.', 'joelho,lombar'),
('Deadlift',                      '45 min', 'alta', 'fortalecimento', 'folicular', 'Levantamento terra. Cadeia posterior completa.', 'lombar'),
('Overhead Press',                '40 min', 'alta', 'fortalecimento', 'folicular', 'Desenvolvimento com barra. Deltóide e core estabilizador.', 'ombro,lombar'),
('Kettlebell Swing',              '35 min', 'alta', 'fortalecimento', 'folicular', 'Potência de quadril. Glúteos, isquios e cardio.', 'lombar'),
('Burpees',                       '30 min', 'alta', 'fortalecimento', 'folicular', 'Corpo inteiro em alta intensidade.', 'joelho,ombro,tornozelo');

-- FOLICULAR | BEM_ESTAR | LEVE
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Yoga Vinyasa leve',             '40 min', 'leve', 'bem_estar', 'folicular', 'Sequências suaves. Transição da fase menstrual.', 'nenhuma');

-- FOLICULAR | BEM_ESTAR | MODERADO
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Yoga Vinyasa dinâmico',         '45 min', 'moderado', 'bem_estar', 'folicular', 'Warrior, Triangle. Força e flexibilidade com energia crescente.', 'joelho'),
('Ciclismo moderado',             '40 min', 'moderado', 'bem_estar', 'folicular', 'Pedalar em terreno plano. Cardio sustentado de baixo impacto.', 'tornozelo');

-- FOLICULAR | BEM_ESTAR | ALTA
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Mountain Climbers',             '30 min', 'alta', 'bem_estar', 'folicular', 'Prancha com joelhos alternados em ritmo acelerado.', 'ombro,tornozelo'),
('HIIT - circuito geral',         '35 min', 'alta', 'bem_estar', 'folicular', 'Circuito de alta intensidade. Energia em ascensão.', 'joelho,tornozelo');


-- ================================================
-- FASE OVULATORIA
-- Pico hormonal: estrogênio + LH + testosterona
-- Foco: performance máxima e recordes pessoais
-- ================================================

-- OVULATORIA | FORTALECIMENTO | LEVE
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Agachamento sumo leve',         '25 min', 'leve', 'fortalecimento', 'ovulatoria', 'Pés afastados, carga leve. Aquecimento para o pico da fase.', 'joelho'),
('Glute Bridge com elástico',     '25 min', 'leve', 'fortalecimento', 'ovulatoria', 'Ponte com faixa nos joelhos. Glúteo médio e máximo.', 'nenhuma');

-- OVULATORIA | FORTALECIMENTO | MODERADO
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Agachamento com barra moderado','40 min', 'moderado', 'fortalecimento', 'ovulatoria', 'Carga moderada. Prepara para progressão máxima.', 'joelho,lombar'),
('Remada unilateral com halter',  '35 min', 'moderado', 'fortalecimento', 'ovulatoria', 'Costas e bíceps com suporte no banco.', 'lombar');

-- OVULATORIA | FORTALECIMENTO | ALTA
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Hip Thrust com barra (pesado)', '45 min', 'alta', 'fortalecimento', 'ovulatoria', 'Extensão de quadril com carga máxima. Melhor fase para PR.', 'lombar'),
('Agachamento 1RM',               '50 min', 'alta', 'fortalecimento', 'ovulatoria', 'Testagem de carga máxima. Pico de força isométrica.', 'joelho,lombar'),
('Power Clean',                   '45 min', 'alta', 'fortalecimento', 'ovulatoria', 'Movimento olímpico explosivo. Potência total.', 'lombar,ombro'),
('Box Jumps',                     '35 min', 'alta', 'fortalecimento', 'ovulatoria', 'Salto explosivo sobre caixa. Potência de membros inferiores.', 'joelho,tornozelo'),
('Jump Squat',                    '35 min', 'alta', 'fortalecimento', 'ovulatoria', 'Agachamento com salto máximo. Pico de testosterona.', 'joelho,tornozelo');

-- OVULATORIA | BEM_ESTAR | LEVE
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Caminhada energizante',         '30 min', 'leve', 'bem_estar', 'ovulatoria', 'Ritmo animado. Aproveita a disposição do pico sem impacto.', 'tornozelo');

-- OVULATORIA | BEM_ESTAR | MODERADO
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Dança livre',                   '40 min', 'moderado', 'bem_estar', 'ovulatoria', 'Alta energia e sociabilidade do pico hormonal.', 'tornozelo'),
('Spinning moderado',             '40 min', 'moderado', 'bem_estar', 'ovulatoria', 'Ciclismo indoor. Cardio sem impacto articular.', 'nenhuma');

-- OVULATORIA | BEM_ESTAR | ALTA
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('HIIT máxima intensidade',       '40 min', 'alta', 'bem_estar', 'ovulatoria', 'Pico hormonal absorve volumes altos com recuperação eficiente.', 'joelho,tornozelo'),
('Sprint 100m',                   '30 min', 'alta', 'bem_estar', 'ovulatoria', 'Velocidade máxima. Melhor momento do ciclo para testar.', 'joelho,tornozelo'),
('Kickboxing',                    '45 min', 'alta', 'bem_estar', 'ovulatoria', 'Potência e coordenação. Testosterona favorece explosividade.', 'ombro,tornozelo'),
('Spinning alta intensidade',     '45 min', 'alta', 'bem_estar', 'ovulatoria', 'Sprints de cadeira e variações de carga intensas.', 'nenhuma');


-- ================================================
-- FASE LUTEA
-- Progesterona dominante, energia decrescente
-- Foco: manutenção, recuperação ativa
-- ================================================

-- LUTEA | BEM_ESTAR | LEVE
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Yin Yoga - Sleeping Swan',      '40 min', 'leve', 'bem_estar', 'lutea', 'Abertura profunda de quadril. 3-5 min por lado.', 'joelho'),
('Viparita Karani',               '15 min', 'leve', 'bem_estar', 'lutea', 'Pernas na parede. Drena retenção de líquido nas pernas.', 'nenhuma'),
('Yoga Nidra',                    '20 min', 'leve', 'bem_estar', 'lutea', 'Relaxamento profundo. Reduz cortisol e TPM emocional.', 'nenhuma'),
('Meditação respiratória',        '15 min', 'leve', 'bem_estar', 'lutea', 'Foco na respiração. Alivia ansiedade pré-menstrual.', 'nenhuma');

-- LUTEA | BEM_ESTAR | MODERADO
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Pilates - Pelvic Curl',         '35 min', 'moderado', 'bem_estar', 'lutea', 'Ponte segmentada vértebra por vértebra. Core sem impacto.', 'nenhuma'),
('Natação moderada',              '35 min', 'moderado', 'bem_estar', 'lutea', 'Água refresca o corpo aquecido pela progesterona.', 'nenhuma'),
('Ciclismo ritmo leve',           '40 min', 'moderado', 'bem_estar', 'lutea', 'Pedalar plano. Aproveita metabolismo lipídico elevado.', 'tornozelo');

-- LUTEA | FORTALECIMENTO | LEVE
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Agachamento goblet',            '30 min', 'leve', 'fortalecimento', 'lutea', 'Halter no peito. Mais reps com menos carga na fase lútea.', 'joelho'),
('Seated Row com elástico',       '25 min', 'leve', 'fortalecimento', 'lutea', 'Remada sentada com faixa. Costas sem carga axial.', 'ombro'),
('Foam roller quadríceps e IT',   '20 min', 'leve', 'fortalecimento', 'lutea', 'Liberação miofascial preventiva antes do próximo ciclo.', 'nenhuma'),
('Prancha modificada',            '20 min', 'leve', 'fortalecimento', 'lutea', 'Joelhos no chão. Core com menor custo energético.', 'ombro');

-- LUTEA | FORTALECIMENTO | MODERADO
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Caminhada nórdica',             '40 min', 'moderado', 'fortalecimento', 'lutea', 'Com bastões. Aproveita metabolismo lipídico elevado.', 'tornozelo'),
('Agachamento com barra leve',    '35 min', 'moderado', 'fortalecimento', 'lutea', 'Carga 20-30% menor que o habitual. Foco em técnica.', 'joelho,lombar'),
('Glute Bridge pesado',           '35 min', 'moderado', 'fortalecimento', 'lutea', 'Ponte com barra ou halter. Mantém estímulo de glúteos.', 'lombar');

-- LUTEA | FORTALECIMENTO | ALTA
-- (para quem tem alta disposição mesmo na fase lútea)
INSERT INTO exercicios (nome, duracao, intensidade, tipo, fase, descricao, restricao_fisica) VALUES
('Treino de força volume alto',   '50 min', 'alta', 'fortalecimento', 'lutea', 'Muitas repetições, carga moderada. Foco em volume, não em carga máxima.', 'joelho,lombar');