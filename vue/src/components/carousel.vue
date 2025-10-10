<!-- <template>
    <br>
    <h1 style="text-align: center;" id="life">照片</h1>
    <div class="carousel">
        <div class="carousel-track">
            <div class="carousel-item">
                <img src="../assets/平潭.jpg" alt="福建平潭的风景照">
                <p class="carousel-explanation">福建平潭</p>
            </div>
            <div class="carousel-item">
                <img src="../assets/武汉.jpg" alt="武汉的风景照">
                <p class="carousel-explanation">武汉</p>
            </div>
            <div class="carousel-item">
                <img src="../assets/龙泉桃花.jpg" alt="龙泉山的桃花">
                <p class="carousel-explanation">龙泉山</p>
            </div>
            <div class="carousel-item">
                <img src="../assets/绿道.jpg" alt="绿道风景">
                <p class="carousel-explanation">绿道</p>
            </div>
            <div class="carousel-item">
                <img src="../assets/绿道2.jpg" alt="绿道风景">
                <p class="carousel-explanation">绿道</p>
            </div>
        </div>
        <button class="carousel-btn prev-btn">&#60;</button>
        <button class="carousel-btn next-btn">&#62;</button>
    </div>
</template>

<script>
export default {
    data() {
        return {
            track: null,
            images: null,
            prevBtn: null,
            nextBtn: null,
            carousel: null,
            currentIndex: 0,
            autoplay: null,
            carouselWidth: 0
        }
    },
    mounted() {
        // 在组件挂载后获取DOM元素
        this.carousel = document.querySelector('.carousel');
        this.track = document.querySelector('.carousel-track');
        this.images = document.querySelectorAll('.carousel img');
        this.prevBtn = document.querySelector('.prev-btn');
        this.nextBtn = document.querySelector('.next-btn');
        
        // 正确计算轮播宽度（包含边框）
        this.carouselWidth = this.carousel.offsetWidth-3;
        
        // 初始化自动播放
        this.autoplay = setInterval(() => this.nextImage(), 3000);
        
        // 绑定事件监听
        this.nextBtn.addEventListener('click', () => this.handleNextClick());
        this.prevBtn.addEventListener('click', () => this.handlePrevClick());
        this.carousel.addEventListener('mouseenter', () => this.pauseAutoplay());
        this.carousel.addEventListener('mouseleave', () => this.resumeAutoplay());
        
        // 窗口大小变化时重新计算宽度
        window.addEventListener('resize', () => {
            this.carouselWidth = this.carousel.offsetWidth;
            this.updatePosition();
        });
    },
    methods: {
        updatePosition() {
            this.track.style.transform = `translateX(-${this.currentIndex * this.carouselWidth}px)`;
        },
        nextImage() {
            this.currentIndex = (this.currentIndex + 1) % this.images.length;
            this.updatePosition();
        },
        prevImage() {
            this.currentIndex = (this.currentIndex - 1 + this.images.length) % this.images.length;
            this.updatePosition();
        },
        handleNextClick() {
            clearInterval(this.autoplay);
            this.nextImage();
        },
        handlePrevClick() {
            clearInterval(this.autoplay);
            this.prevImage();
        },
        pauseAutoplay() {
            clearInterval(this.autoplay);
        },
        resumeAutoplay() {
            this.autoplay = setInterval(() => this.nextImage(), 3000);
        }
    },
    beforeUnmount() {
        // 组件卸载时清除事件监听和定时器
        clearInterval(this.autoplay);
        this.nextBtn.removeEventListener('click', this.handleNextClick);
        this.prevBtn.removeEventListener('click', this.handlePrevClick);
        this.carousel.removeEventListener('mouseenter', this.pauseAutoplay);
        this.carousel.removeEventListener('mouseleave', this.resumeAutoplay);
        window.removeEventListener('resize', () => {});
    }
}
</script>

<style scoped>
.carousel {
    width: 600px;
    height: 400px;
    margin-left: auto;
    margin-right: auto;
    overflow: hidden;
    border: 2px solid #ccc;
    border-radius: 10px;
    position: relative;
    box-sizing: border-box; /* 确保边框包含在宽度计算中 */
}

.carousel-track {
    display: flex;
    height: 100%;
    transition: transform 0.5s ease;
}

.carousel-item {
    min-width: 100%;
    width: 100%;
    height: 100%;
    position: relative;
}

.carousel img {
    width: 100%;
    height: 100%;
    flex-shrink: 0;
    object-fit: cover;
}

.carousel-btn {
    position: absolute;
    top: 50%;
    transform: translateY(-50%);
    width: 40px;
    height: 40px;
    background: rgba(0, 0, 0, 0.5);
    color: white;
    border: none;
    border-radius: 50%;
    cursor: pointer;
    z-index: 10;
    font-size: 18px;
    display: flex;
    align-items: center;
    justify-content: center;
    transition: background 0.3s ease;
}

.carousel-btn:hover {
    background: rgba(0, 0, 0, 0.7);
}

.carousel-explanation {
    text-align: center;
    background-color: rgba(0, 0, 0, 0.5);
    color: white;
    position: absolute;
    bottom: 0;
    width: 100%;
    margin: 0;
    padding: 8px 0;
}

.prev-btn {
    left: 10px;
}

.next-btn {
    right: 10px;
}

/* 响应式调整 */
@media (max-width: 768px) {
    .carousel {
        width: 90%;
        height: 300px;
    }
}
</style> -->








<template>
    <div>
        <br>
        <h1 style="text-align: center;" id="life">照片</h1>
        <div class="carousel" ref="carousel" @mouseenter="pauseAutoplay" @mouseleave="resumeAutoplay">
            <div class="carousel-track" :style="{ transform: `translateX(-${currentIndex * carouselWidth}px)` }">
                <div class="carousel-item" v-for="(photo, index) in photos" :key="index">
                    <img :src="photo.src" :alt="photo.alt">
                    <p class="carousel-explanation">{{ photo.location }}</p>
                </div>
            </div>
            <button class="carousel-btn prev-btn" @click="prevImage">&#60;</button>
            <button class="carousel-btn next-btn" @click="nextImage">&#62;</button>
        </div>
    </div>
</template>

<script>
export default {
    data() {
        return {
            currentIndex: 0,
            autoplay: null,
            carouselWidth: 0,
            // 照片数据集中管理
            photos: [
                {
                    src: "/src/assets/平潭.jpg",
                    alt: "福建平潭的风景照",
                    location: "福建平潭"
                },
                {
                    src: "/src/assets/武汉.jpg",
                    alt: "武汉的风景照",
                    location: "武汉"
                },
                {
                    src: "/src/assets/龙泉桃花.jpg",
                    alt: "龙泉山的桃花",
                    location: "龙泉山"
                },
                {
                    src: "/src/assets/绿道.jpg",
                    alt: "绿道风景",
                    location: "绿道"
                },
                {
                    src: "/src/assets/绿道2.jpg",
                    alt: "绿道风景",
                    location: "绿道"
                }
            ]
        };
    },
    mounted() {
        // 使用Vue的ref获取DOM元素
        this.carouselWidth = this.$refs.carousel.offsetWidth - 3;
        this.startAutoplay();

        // 窗口大小变化监听
        window.addEventListener('resize', this.handleResize);
    },
    methods: {
        // 下一张图片
        nextImage() {
            this.currentIndex = (this.currentIndex + 1) % this.photos.length;
        },
        // 上一张图片
        prevImage() {
            this.currentIndex = (this.currentIndex - 1 + this.photos.length) % this.photos.length;
        },
        // 处理下一张点击
        // handleNextClick() {
        //     //this.pauseAutoplay();
        //     this.nextImage();
        //    // this.resumeAutoplay();
        // },
        // // 处理上一张点击
        // handlePrevClick() {
        //   //  this.pauseAutoplay();
        //     this.prevImage();
        //    // this.resumeAutoplay();
        // },
        // 开始自动播放
        startAutoplay() {
            this.autoplay = setInterval(() => this.nextImage(), 3000);
        },
        // 暂停自动播放
        pauseAutoplay() {
            clearInterval(this.autoplay);
        },
        // 恢复自动播放
        resumeAutoplay() {
            this.startAutoplay();
        },
        // 处理窗口大小变化
        handleResize() {
            this.carouselWidth = this.$refs.carousel.offsetWidth;
        }
    },
    beforeUnmount() {
        // 清理定时器和事件监听
        clearInterval(this.autoplay);
        window.removeEventListener('resize', this.handleResize);
    }
};
</script>

<style scoped>
.carousel {
    width: 600px;
    height: 400px;
    margin-left: auto;
    margin-right: auto;
    overflow: hidden;
    border: 2px solid #ccc;
    border-radius: 10px;
    position: relative;
    box-sizing: border-box;
    /* 确保边框包含在宽度计算中 */
}

.carousel-track {
    display: flex;
    height: 100%;
    transition: transform 0.5s ease;
}

.carousel-item {
    min-width: 100%;
    width: 100%;
    height: 100%;
    position: relative;
}

.carousel img {
    width: 100%;
    height: 100%;
    flex-shrink: 0;
    object-fit: cover;
}

.carousel-btn {
    position: absolute;
    top: 50%;
    transform: translateY(-50%);
    width: 40px;
    height: 40px;
    background: rgba(0, 0, 0, 0.5);
    color: white;
    border: none;
    border-radius: 50%;
    cursor: pointer;
    z-index: 10;
    font-size: 18px;
    display: flex;
    align-items: center;
    justify-content: center;
    transition: background 0.3s ease;
}

.carousel-btn:hover {
    background: rgba(0, 0, 0, 0.7);
}

.carousel-explanation {
    text-align: center;
    background-color: rgba(0, 0, 0, 0.5);
    color: white;
    position: absolute;
    bottom: 0;
    width: 100%;
    margin: 0;
    padding: 8px 0;
}

.prev-btn {
    left: 10px;
}

.next-btn {
    right: 10px;
}

/* 响应式调整 */
@media (max-width: 768px) {
    .carousel {
        width: 90%;
        height: 300px;
    }
}
</style>
