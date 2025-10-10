<template>
  <div class="cards-container">
    <!-- 3D旋转容器 -->
    <div 
      class="rotation-container" 
      :class="{ paused: isPaused }"
      @mouseenter="isPaused = true"
      @mouseleave="isPaused = false"
    >
      <!-- 卡片列表 -->
      <div 
        class="cards-wrapper" 
        :style="{ transform: `rotateY(${rotationDeg}deg)` }"
      >
        <!-- 各个技术卡片 -->
        <div 
          class="card" 
          v-for="(tech, index) in technologies" 
          :key="tech.id"
          :style="{ transform: `rotateY(${index * (360 / technologies.length)}deg) translateZ(${cardRadius}px)` }"
          @click="showDetail(tech)"
        >
          <div class="card-inner">
            <div class="card-front">
              <div class="card-icon">{{ tech.icon }}</div>
              <h3 class="card-title">{{ tech.name }}</h3>
              <div class="card-overlay">点击查看详情</div>
            </div>
          </div>
        </div>
      </div>
    </div>

    <!-- 详情弹窗 -->
    <div class="modal" v-if="selectedTech" @click="closeDetail()">
      <div class="modal-content" @click.stop>
        <button class="close-btn" @click="closeDetail()">&times;</button>
        <h2 class="modal-title">{{ selectedTech.name }}</h2>
        <div class="modal-icon">{{ selectedTech.icon }}</div>
        <p class="modal-description">{{ selectedTech.description }}</p>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      // 旋转状态
      isPaused: false,
      rotationDeg: 0,
      // 卡片配置
      cardRadius: 250,
      rotationSpeed: 0.5,
      // 技术卡片数据
      technologies: [
        {
          id: 1,
          name: "C语言",
          icon: "C",
          description: "C语言是一种通用的、面向过程式的计算机编程语言。它广泛应用于系统软件与应用软件的开发，具有高效、灵活和可移植性等特点。"
        },
        {
          id: 2,
          name: "HTML",
          icon: "<>",
          description: "HTML（超文本标记语言）是用于创建网页的标准标记语言。它描述了网页的结构，使用一系列标签来定义内容的不同部分。"
        },
        {
          id: 3,
          name: "CSS",
          icon: "CSS",
          description: "CSS（层叠样式表）是一种用于描述HTML或XML文档呈现的样式表语言。它控制网页的布局和外观，实现内容与表现的分离。"
        },
        {
          id: 4,
          name: "JavaScript",
          icon: "JS",
          description: "JavaScript是一种高级的、解释型的编程语言。它是网页的核心技术之一，可用于实现网页的交互效果，以及服务器端编程等。"
        },
        {
          id: 5,
          name: "Vue",
          icon: "V",
          description: "Vue是一套用于构建用户界面的渐进式JavaScript框架。它的核心库只关注视图层，易于上手，同时也能与其他库或现有项目整合。"
        },
        {
          id: 6,
          name: "Linux",
          icon: "L",
          description: "Linux是一种自由和开放源代码的类UNIX操作系统。它广泛应用于服务器、嵌入式系统和个人计算机等领域，以稳定性和安全性著称。"
        }
      ],
      // 选中的技术卡片
      selectedTech: null
    };
  },
  methods: {
    // 旋转动画
    rotateCards() {
      if (!this.isPaused) {
        this.rotationDeg = (this.rotationDeg + this.rotationSpeed) % 360;
      }
      requestAnimationFrame(this.rotateCards);
    },
    // 显示详情
    showDetail(tech) {
      this.selectedTech = tech;
      // 显示详情时暂停旋转
      this.isPaused = true;
    },
    // 关闭详情
    closeDetail() {
      this.selectedTech = null;
    }
  },
  mounted() {
    // 启动旋转动画
    this.rotateCards();
  }
};
</script>

<style scoped>
/* 容器样式 */
.cards-container {
  width: 900px;
  height: 600px;
  display: flex;
  justify-content: center;
  align-items: center;
  background-color: var(--bg-light);
  perspective: 1000px;
  overflow: hidden;
}

/* 旋转容器 */
.rotation-container {
  position: relative;
  width: 100%;
  height: 100%;
  transform-style: preserve-3d;
}

/* 卡片 wrapper */
.cards-wrapper {
  position: absolute;
  width: 100%;
  height: 100%;
  transform-style: preserve-3d;
  transition: transform 0.5s ease;
}

/* 单个卡片样式 */
.card {
  position: absolute;
  top: 50%;
  left: 50%;
  width: 200px;
  height: 280px;
  margin: -140px 0 0 -100px;
  transform-style: preserve-3d;
  cursor: pointer;
  transition: var(--transition);
}

.card:hover {
  transform: rotateY(var(--rotation)) translateZ(calc(var(--card-radius) + 30px)) scale(1.05);
  z-index: 10;
}

/* 卡片内部样式 */
.card-inner {
  position: relative;
  width: 100%;
  height: 100%;
  transform-style: preserve-3d;
  transition: var(--transition);
}

/* 卡片正面 */
.card-front {
  position: absolute;
  width: 100%;
  height: 100%;
  backface-visibility: hidden;
  background-color: white;
  border-radius: 12px;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  box-shadow: var(--shadow);
  background: linear-gradient(135deg, white, var(--primary-light));
  transition: var(--transition);
}

.card:hover .card-front {
  box-shadow: 0 8px 24px rgba(0, 0, 0, 0.15);
}

/* 卡片图标 */
.card-icon {
  font-size: 50px;
  font-weight: bold;
  color: var(--primary-color);
  margin-bottom: 20px;
  transition: var(--transition);
}

.card:hover .card-icon {
  color: var(--primary-dark);
  transform: scale(1.1);
}

/* 卡片标题 */
.card-title {
  font-size: 24px;
  color: var(--text-dark);
  margin: 0 0 15px 0;
  text-align: center;
}

/* 卡片悬停提示 */
.card-overlay {
  position: absolute;
  bottom: 15px;
  font-size: 14px;
  color: var(--text-light);
  opacity: 0;
  transition: var(--transition);
}

.card:hover .card-overlay {
  opacity: 1;
}

/* 弹窗样式 */
.modal {
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background-color: rgba(0, 0, 0, 0.7);
  display: flex;
  justify-content: center;
  align-items: center;
  z-index: 100;
  animation: fadeIn 0.3s ease;
}

.modal-content {
  background-color: white;
  border-radius: 12px;
  width: 90%;
  max-width: 600px;
  padding: 30px;
  position: relative;
  animation: scaleIn 0.3s ease;
}

.close-btn {
  position: absolute;
  top: 15px;
  right: 15px;
  font-size: 24px;
  background: none;
  border: none;
  cursor: pointer;
  color: var(--text-light);
  transition: var(--transition);
}

.close-btn:hover {
  color: var(--text-dark);
  transform: rotate(90deg);
}

.modal-title {
  color: var(--primary-dark);
  margin-top: 0;
  margin-bottom: 20px;
  text-align: center;
}

.modal-icon {
  font-size: 60px;
  font-weight: bold;
  color: var(--primary-color);
  text-align: center;
  margin-bottom: 25px;
}

.modal-description {
  color: var(--text-dark);
  line-height: 1.6;
  font-size: 16px;
}

/* 动画效果 */
@keyframes fadeIn {
  from { opacity: 0; }
  to { opacity: 1; }
}

@keyframes scaleIn {
  from { transform: scale(0.8); opacity: 0; }
  to { transform: scale(1); opacity: 1; }
}

/* 响应式调整 */
@media (max-width: 768px) {
  .card {
    width: 160px;
    height: 220px;
    margin: -110px 0 0 -80px;
  }
  
  .card-title {
    font-size: 20px;
  }
  
  .card-icon {
    font-size: 40px;
  }
  
  
}
</style>
