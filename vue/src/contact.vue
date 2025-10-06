<template>
    <div class="contact-section" id="contact">
        <h2 class="section-title">联系我</h2>
        <div class="contact-container">
            <!-- 邮箱联系卡片 -->
            <div class="contact-card">
                <div class="contact-icon">
                    <i class="fas fa-envelope"></i>
                </div>
                <h3>邮箱</h3>
                <p>随时发送邮件咨询</p>
                <p>1010958435@qq.com</p>
            </div>

            <!-- 电话联系卡片 -->
            <div class="contact-card">
                <div class="contact-icon">
                    <i class="fas fa-phone"></i>
                </div>
                <h3>电话</h3>
                <p>每天9:00-23:00接听</p>
                <p>+86 173 1955 1236</p>
            </div>

            <!-- 微信联系卡片 -->
            <div class="contact-card">
                <div class="contact-icon">
                    <i class="fab fa-weixin"></i>
                </div>
                <h3>微信</h3>
                <p>添加好友咨询</p>
                <p>wxid_pc62umw22ef322</p>
            </div>
        </div>
    </div>
</template>
<style scoped>
.contact-section {
      background-color: white;
      padding: 40px 30px;
      border-radius: 12px;
      box-shadow: var(--shadow);
      margin: 40px auto;
      max-width: 1000px;
  }

  .contact-container {
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
      gap: 25px;
  }

  .contact-card {
      background-color: var(--primary-light);
      border-radius: 10px;
      padding: 25px;
      text-align: center;
      transition: var(--transition);
  }

  .contact-card:hover {
      transform: translateY(-10px);
      box-shadow: 0 10px 20px rgba(0, 0, 0, 0.1);
  }

  .contact-icon {
      font-size: 2.5rem;
      color: var(--primary-dark);
      margin-bottom: 15px;
  }

  .contact-card h3 {
      color: var(--primary-dark);
      margin-bottom: 10px;
  }

  .contact-card p {
      color: var(--text-light);
  }

  .section-title {
      text-align: center;
      margin-bottom: 30px;
      color: var(--primary-dark);
  }
</style>