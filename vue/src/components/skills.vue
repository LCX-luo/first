<template>
    <div id="skills" class="skills-section">
        <h2 class="section-title">我的技能</h2>
        <div class="skills-container">
            <div class="skill-card">
                <h3>编程能力</h3>
                <p>掌握c、JavaScript等编程语言，正在学习Web开发和vue</p>
            </div>
            <div class="skill-card">
                <h3>旅行规划</h3>
                <p>擅长制定详细旅行计划，能发现小众景点和特色美食</p>
            </div>
            <div class="skill-card">
                <h3>骑行技巧</h3>
                <p>有多年骑行经验，熟悉各类骑行路线规划和安全知识</p>
            </div>
        </div>
    </div>
</template>
<style scoped>
.skills-section {
      background-color: white;
      padding: 40px 30px;
      border-radius: 12px;
      box-shadow: var(--shadow);
      margin: 40px auto;
      max-width: 1000px;
  }

  .skills-container {
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
      gap: 25px;
  }

  .skill-card {
      background-color: var(--primary-light);
      border-radius: 10px;
      padding: 25px;
      text-align: center;
      transition: var(--transition);
  }

  .skill-card:hover {
      transform: translateY(-10px);
      box-shadow: 0 10px 20px rgba(0, 0, 0, 0.1);
  }

  .skill-icon {
      font-size: 2.5rem;
      color: var(--primary-dark);
      margin-bottom: 15px;
  }

  .skill-card h3 {
      color: var(--primary-dark);
      margin-bottom: 10px;
  }

  .skill-card p {
      color: var(--text-light);
  }


  .section-title {
      text-align: center;
      margin-bottom: 30px;
      color: var(--primary-dark);
  }
</style>